#include "IncomeExpenseManager.h"

IncomeExpenseManager::IncomeExpenseManager(string incomeFileName, string expenseFileName, int loggedInUserId): incomeFile(incomeFileName), expenseFile(expenseFileName)
{
   incomes=incomeFile.loadEntriesFromFile(loggedInUserId);
   expenses=expenseFile.loadEntriesFromFile(loggedInUserId);
   startDate=0;
   endDate=99999999999;
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



void IncomeExpenseManager::showBalanceSheetFromActualMonth()
{
    setStartDate(1602975600);
    setEndDate(1603133173);
    showBalanceSheet();

}

void IncomeExpenseManager::showBalanceSheetFromPreviousMonth()
{
    setStartDate(1602975600);
    setEndDate(1603133173);
    showBalanceSheet();
}

void IncomeExpenseManager::showBalanceSheetFromGivenPeriod()
{
    setStartDate(1602975600);
    setEndDate(1603133173);
    showBalanceSheet();

}

void IncomeExpenseManager::showBalanceSheet()
{
    showIncomes();
    showExpenses();
    showBalance();
}


void IncomeExpenseManager::showIncomes()
{
    vector<Entry> selectedIncomes = getEntriesFromSelectedPeriod(incomes);
    if (!selectedIncomes.empty())
    {
        cout << "                              >>> INCOMES <<<                                   " <<endl;
        cout << "--------------------------------------------------------------------------------" <<endl;
        cout << "  ID                       DESCRIPTION                    DATE          AMOUNT  " <<endl;
        cout << "--------------------------------------------------------------------------------" <<endl;
        for (vector <Entry> :: iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++)
        {
            showEntryData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "No incomes registered." << endl << endl;
    }
    //system("pause");
}

void IncomeExpenseManager::showExpenses()
{
    vector<Entry> selectedExpenses = getEntriesFromSelectedPeriod(expenses);
    if (!selectedExpenses.empty())
    {
        cout << "                              >>> EXPENSES <<<                                  " <<endl;
        cout << "--------------------------------------------------------------------------------" <<endl;
        cout << "  ID                       DESCRIPTION                    DATE          AMOUNT  " <<endl;
        cout << "--------------------------------------------------------------------------------" <<endl;
        for (vector <Entry> :: iterator itr = selectedExpenses.begin(); itr != selectedExpenses.end(); itr++)
        {
            showEntryData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "No expenses registered for this period." << endl << endl;
    }
    //system("pause");
}

vector <Entry> IncomeExpenseManager::getEntriesFromSelectedPeriod( const vector<Entry> &entries)
{
    vector<Entry> selectedEntries;
    copy_if(entries.begin(), entries.end(), back_inserter(selectedEntries),
            [=](Entry entry){return ((entry.getDate()>=startDate)&&(entry.getDate()<=endDate));});

    return selectedEntries;
}

void IncomeExpenseManager::showEntryData(Entry entry)
{

    cout << setw(2)<<" ";
    cout << setw(8) << left << entry.getId();
    cout << setw(45) << left <<entry.getDescription();

    cout << setw(13)<< left << Date::convertToString(entry.getDate());
    cout << setw (10) << right <<Money::convertToString(entry.getAmount()) << endl;

}

int IncomeExpenseManager::sumAllEntries(const vector <Entry> &entries)
{
    int sum = 0;
    for_each(entries.begin(), entries.end(),
             [&](Entry entry){sum+= entry.getAmount();});
    return sum;
}

int IncomeExpenseManager::calculateBalance()
{
    int balance=0;
    balance=sumAllEntries(getEntriesFromSelectedPeriod(incomes))-sumAllEntries(getEntriesFromSelectedPeriod(expenses));
    return balance;
}

void IncomeExpenseManager::showBalance()
{
    cout << "--------------------------------------------------------------------------------" <<endl;
    cout << " Balance:";
    cout <<setw(69)<<right<<Money::convertToString(calculateBalance())<<endl;

    return;
}
