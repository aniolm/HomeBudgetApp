#include "IncomeExpenseFile.h"

IncomeExpenseFile::IncomeExpenseFile(string fileName):FILE_NAME(fileName), lastEntryId(0)
{
    getLastEntryIdFromFile();
}

void IncomeExpenseFile::getLastEntryIdFromFile()
{
    int lastId = 0;
    int currentId = 0;
    CMarkup xml;
    xml.Load( FILE_NAME );
    while ( xml.FindElem("ENTRY" ))
    {
    xml.IntoElem();
    xml.FindElem( "ID" );
    currentId = atoi( MCD_2PCSZ(xml.GetData()));
    if ( currentId  > lastId )
        lastId = currentId;
    }
    lastEntryId=lastId;
    return;
}

void IncomeExpenseFile::appendEntryToFile(Entry entry)
{
    CMarkup xml;
    xml.Load( FILE_NAME );

    xml.AddElem( "ENTRY" );
    xml.IntoElem();
    xml.AddElem("ID", entry.getId());
    xml.AddElem( "USERID", entry.getUserId());
    xml.AddElem( "DESCRIPTION", entry.getDescription());
    xml.AddElem("AMOUNT", entry.getAmount());
    xml.AddElem( "DATE", entry.getDate());

    xml.Save( FILE_NAME );

    return;
}
