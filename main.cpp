#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QException>
#include <QTextCodec>
#include "names_man_exception.h"
#include "name_info_reader.h"
#include <QCommandLineParser>

QTextStream cout(stdout);



void Error( const QString& report )
{
    throw NamesManException( report );
}

int main(int argc, char *argv[])
{
#ifdef WIN32
    cout.setCodec( QTextCodec::codecForName( "CP866" ) );
#endif
    QCoreApplication a(argc, argv);
    QCommandLineParser parser;

    QCommandLineOption optOutFile( "o", "Задает выходной файл для записи сгенерированных ФИО", "имя файла", "" );
    parser.addOption( optOutFile );
    QCommandLineOption optInFile( "i", "Задает входной файл со списком ФИО для проверки", "имя файла", "" );
    parser.addOption( optInFile );
    QCommandLineOption optLogFile( "g", "Задает выходной файл для записи результатов проверки", "имя файла", "" );
    parser.addOption( optLogFile );

    parser.addPositionalArgument( "nameListFile", "Входной файл со словарем имен." );
    parser.process( a );

    //cout << optOutFile.description() << endl;
    try {
        if ( argc < 2 )
        {
            cout << parser.helpText() << endl;
            return 0;
        };
            //Error( "Первым аргументом командной строки должно быть имя входного файла." );
        QStringList lArgs = parser.positionalArguments();
        if ( lArgs.size() == 0 )
            Error( "Первым аргументом командной строки должно быть имя входного файла со словарем имен." );
        QFile fileIn( lArgs[0] );//argv[1] );
        if ( !fileIn.open( QIODevice::ReadOnly ) )
            Error( QString( "Не удалось открыть файл '" ) + lArgs[0] /*argv[1]*/ + "'" );
        QTextStream streamIn( &fileIn );

        VecNameInfo info = ReadNameInfo( streamIn );
        if ( parser.isSet( optOutFile ) )
        {
            VecNameRecord vRec = GenerateNameRecords( info );
            QString sOutFile = parser.value( optOutFile );
            QFile fileOut( sOutFile );
            if ( !fileOut.open( QIODevice::WriteOnly ) )
                Error( QString( "Не удалось открыть файл '" ) + sOutFile + "'" );
            QTextStream streamOut( &fileOut );
            WriteNameRecords( streamOut, vRec );
        };
        if ( parser.isSet( optInFile ) )
        {
            QString sInFile = parser.value( optInFile );
            QFile fileTest( sInFile );
            if ( !fileTest.open( QIODevice::ReadOnly ) )
                Error( QString( "Не удалось открыть файл '" ) + sInFile + "'" );
            QTextStream streamTest( &fileTest );
            VecNameRecord vRec = ReadNameRecords( streamTest );
            QTextStream *pout = &cout;
            QFile fileLog;
            QTextStream streamLog;
            if ( parser.isSet( optLogFile ) )
            {
                QString sLogFile = parser.value( optLogFile );
                fileLog.setFileName( sLogFile );
                if ( !fileLog.open( QIODevice::WriteOnly ) )
                    Error( QString( "Не удалось открыть файл '" ) + sLogFile + "'" );
                streamLog.setDevice( &fileLog );
                pout = &streamLog;
            };
            VerifyNames( vRec, info, *pout );
        };
    }
    catch ( NamesManException& ex )
    {
        QString str = QString::fromLocal8Bit( ex.what() );
        cout << QString( "ОШИБКА: " ) << str << endl;
        return 0;
    };
    return 0;
}
