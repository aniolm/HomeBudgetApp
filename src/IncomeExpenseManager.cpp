#include "IncomeExpenseManager.h"

IncomeExpenseManager::IncomeExpenseManager(string incomeFileName, string expenseFileName): incomeFile(incomeFileName), expenseFile(expenseFileName)
{
   incomes=incomeFile.loadEntriesFromFile();
   expenses=expenseFile.loadEntriesFromFile();
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
        incomeFile.getLastEntryIdFromFile();
        entry.setId(incomeFile.getLastEntryId()+1);
    }

    else if (type==1)
    {
        expenseFile.getLastEntryIdFromFile();
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

void IncomeExpenseManager::showAllIncomes()
{
    system("cls");
    if (!incomes.empty())
    {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Entry> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            showEntryData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "No incomes registered." << endl << endl;
    }
    system("pause");
}

void IncomeExpenseManager::showAllExpenses()
{
    system("cls");
    if (!expenses.empty())
    {
        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Entry> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            showEntryData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "No expenses registered." << endl << endl;
    }
    system("pause");
}

void IncomeExpenseManager::showEntryData(Entry entry)
{
    cout << endl << "Id:                 " << entry.getId() << endl;
    cout << "Description:               " << entry.getDescription()<< endl;
    cout << "Date:           " << entry.getDate()<< endl;
    cout << "Numer telefonu:     " << entry.getAmount() << endl;

}
