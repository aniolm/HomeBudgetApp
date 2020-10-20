#include "IncomeExpenseFile.h"

IncomeExpenseFile::IncomeExpenseFile(string fileName):FILE_NAME(fileName), lastEntryId(0)
{

}

void IncomeExpenseFile::getLastEntryIdFromFile()
{
    int lastId = 0;
    int currentId = 0;
    CMarkup xml;
    xml.Load( FILE_NAME );
    while ( xml.FindElem("ENTRY"))
    {
    xml.IntoElem();

    xml.FindElem( "ID" );
    currentId = atoi( MCD_2PCSZ(xml.GetData()));
    if ( currentId  > lastId )
        lastId = currentId;
    xml.OutOfElem();
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

vector <Entry> IncomeExpenseFile::loadEntriesFromFile(int loggedInUserId)
{
    vector <Entry> entries;
    Entry entry;
    CMarkup xml;
    xml.Load( FILE_NAME );

    while ( xml.FindElem("ENTRY" ))
    {
    xml.IntoElem();
    xml.FindElem( "ID" );
    entry.setId(  atoi( MCD_2PCSZ(xml.GetData()) ) );
    xml.FindElem( "USERID" );
    if (FILE_NAME=="IncomeFile.xml")
    {
        entry.setType(0);
    }
    else if (FILE_NAME=="ExpenseFile.xml")
    {
        entry.setType(1);
    }
    entry.setUserId(  atoi( MCD_2PCSZ(xml.GetData()) ) );
    xml.FindElem( "DESCRIPTION" );
    entry.setDescription( xml.GetData() );
    xml.FindElem( "AMOUNT" );
    entry.setAmount( atoi( MCD_2PCSZ(xml.GetData()) ));
    xml.FindElem( "DATE" );
    entry.setDate( atoi( MCD_2PCSZ(xml.GetData()) ));
    xml.OutOfElem();
    entries.push_back(entry);
    }

    return entries;

}
