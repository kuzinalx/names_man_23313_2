#include "name_info_reader.h"


void WriteNameRecords( QTextStream& stream, const VecNameRecord& vrec )
{
    // TODO
    stream << QString("Вызвана ") <<"WriteNameRecords" << endl;
}

VecNameRecord ReadNameRecords( QTextStream& stream )
{
    // TODO
    return VecNameRecord();
}

void VerifyNames( const VecNameRecord& vrec, const VecNameInfo& info, QTextStream& log )
{
    // TODO
    log << QString("Вызвана ") <<"VerifyNames" << endl;
}


