#include "IncomeExpenseManager.h"

IncomeExpenseManager::IncomeExpenseManager(string incomeFileName, string expenseFileName): incomeFile(incomeFileName), expenseFile(expenseFileName)
{

}

void IncomeExpenseManager::addEntry(int loggedInUserId, int type)
{
    Entry entry;
    system("cls");
    cout << " >>> ADD NEW ENTRY TO THE BALANCE SHEET <<<" << endl << endl;
    entry = inputNewEntryData(loggedInUserId,type);

    if(type==0)
    {
        incomes.push_back(entry);
        incomeFile.appendEntryToFile(entry);
    }

    else if (type==1)
    {
        expenses.push_back(entry);
        expenseFile.appendEntryToFile(entry);
    }

    else
    {
        cout << "Wrong entry type used!!!";
    }

    return;
}

Entry IncomeExpenseManager::inputNewEntryData(int loggedInUserId, int type)
{
    Entry entry;

    if(type==0)
    {
        entry.setId(incomeFile.getLastEntryId()+1);
    }

    else if (type==1)
    {
        entry.setId(expenseFile.getLastEntryId()+1);
    }

    else
    {
        cout << "Wrong entry type used!!!";
        return entry;
    }

    entry.setUserId(loggedInUserId);

    entry.setType(type);

    if(type==0)
    {
        cout << "Enter income description: ";
    }

    else if (type==1)
    {
        cout << "Enter expense description: ";
    }

    entry.setDescription(AuxMethods::getLine());


    entry.setAmount(Money::enterAmount());

    cout << "Save with current date/time? (y/n)";

    if (AuxMethods::inputYesNo())
    {
        entry.setDate(Date::getCurrentDate());
    }

    else
    {
        entry.setDate(Date::enterDate());
    }

    return entry;
}
