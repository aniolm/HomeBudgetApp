#include "IncomeExpenseManager.h"

IncomeExpenseManager::IncomeExpenseManager(string incomeFileName, string expenseFileName, int loggedInUserId): incomeFile(incomeFileName),
                      expenseFile(expenseFileName), lastEntryId(0), startDate(0), endDate(99999999999)

{
   incomes=incomeFile.loadEntriesFromFile(loggedInUserId);
   expenses=expenseFile.loadEntriesFromFile(loggedInUserId);
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
        findLastEntryId(incomes);
        entry.setId(lastEntryId+1);
    }

    else if (type==1)
    {
        findLastEntryId(expenses);
        entry.setId(lastEntryId+1);
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
    cout<<endl;
    entry.setAmount(Money::enterAmount());

    cout << "Save new entry with the current date? (y/n): ";

    if (AuxMethods::inputYesNo())
    {
        entry.setDate(Date::getCurrentDate());
    }

    else
    {
        cout<<endl;
        cout <<"Enter new date using format 'dd-mm-yyyy': ";
        entry.setDate(Date::enterDate());
    }

    return entry;
}



void IncomeExpenseManager::showBalanceSheetFromActualMonth()
{
    int year = (Date::getCurrentYear());
    int month = (Date::getCurrentMonth());
    struct tm startDate{};
    startDate.tm_year = (year-1900);
    startDate.tm_mon = (month-1);
    startDate.tm_mday = 1;

    struct tm endDate{};
    endDate.tm_year = (year-1900);
    endDate.tm_mon = (month-1);
    endDate.tm_mday = (Date::getNumberOfDays(month, year));

    setStartDate(mktime(&startDate));
    setEndDate(mktime(&endDate));
    showBalanceSheet();

}

void IncomeExpenseManager::showBalanceSheetFromPreviousMonth()
{
    int year = (Date::getPreviousYear());
    int month = (Date::getPreviousMonth());
    struct tm startDate{};
    startDate.tm_year = (year-1900);
    startDate.tm_mon = (month-1);
    startDate.tm_mday = 1;

    struct tm endDate{};
    endDate.tm_year = (year-1900);
    endDate.tm_mon = (month-1);
    endDate.tm_mday = (Date::getNumberOfDays(month, year));

    setStartDate(mktime(&startDate));
    setEndDate(mktime(&endDate));
    showBalanceSheet();
}

void IncomeExpenseManager::showBalanceSheetFromGivenPeriod()
{
    cout<<endl;
    cout<<"Enter start date using format 'dd-mm-yyyy': ";
    setStartDate((Date::enterDate()));
    cout<<"Enter end date using format 'dd-mm-yyyy': ";
    setEndDate((Date::enterDate()));
    showBalanceSheet();

}

void IncomeExpenseManager::showBalanceSheet()
{
    showTimePeriod();
    showIncomes();
    showExpenses();
    showBalance();
    system("pause");
}


void IncomeExpenseManager::showTimePeriod()
{
    cout<<endl;
    cout << "Selected period:  "<<(Date::convertToString(startDate))<<" - "<<(Date::convertToString(endDate))<<endl<<endl;
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
        cout << endl << "No incomes registered for selected period." << endl << endl;
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
        cout << endl << "No expenses registered for selected period." << endl << endl;
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
    cout << setw (10) << right << Money::convertToString(entry.getAmount()) << endl;

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
    cout <<setw(69)<<right<<Money::convertToString(calculateBalance())<<endl<<endl;

    return;
}


void  IncomeExpenseManager::findLastEntryId(vector<Entry> entries)
{
    vector<Entry>::iterator highestId;
    if (entries.size()>0)
    {
        highestId= max_element(entries.begin(), entries.end(),[](Entry& lhs, Entry& rhs){return lhs.getId() < rhs.getId();});
        lastEntryId = (*highestId).getId();
    }
    else
    {
        lastEntryId=0;
    }
    return;
}
