#ifndef NAME_INFO_READER
#define NAME_INFO_READER

#include "name_info.h"
#include <QVector>
#include <QTextStream>


typedef QVector< NameInfo > VecNameInfo;

VecNameInfo ReadNameInfo( QTextStream& stream );

struct NameRecord
{
    QString name;
    QString surname;
    QString fathername;
};

typedef QVector< NameRecord > VecNameRecord;

VecNameRecord GenerateNameRecords( const VecNameInfo& info );

void WriteNameRecords( QTextStream& stream, const VecNameRecord& vrec );
VecNameRecord ReadNameRecords( QTextStream& stream );

void VerifyNames( const VecNameRecord& vrec, const VecNameInfo& info, QTextStream& log );


#endif // NAME_INFO_READER

