#ifndef INCOMEEXPENSEMANAGER_H
#define INCOMEEXPENSEMANAGER_H
#include "Entry.h"
#include "IncomeExpenseFile.h"
#include "AuxMethods.h"
#include "Date.h"
#include "Money.h"
#include <vector>
#include <iomanip>
#include <algorithm>
#include <ctime>

using std::vector;
using std::setw;
using std::left;
using std::right;

class IncomeExpenseManager
{
    public:
        IncomeExpenseManager(string incomeFileName, string expenseFileName, int loggedInUserId);
        time_t getStartDate() { return startDate; };
        void setStartDate(time_t val) { startDate = val; };
        time_t getEndDate() { return endDate; };
        void setEndDate(time_t val) { endDate = val; };
        void addEntry(int loggedInUserId, int type);
        void showBalanceSheetFromActualMonth();
        void showBalanceSheetFromPreviousMonth();
        void showBalanceSheetFromGivenPeriod();

    protected:

    private:
        vector <Entry> incomes;
        vector <Entry> expenses;
        IncomeExpenseFile incomeFile;
        IncomeExpenseFile expenseFile;
        time_t startDate;
        time_t endDate;

        Entry inputNewEntryData(int loggedInUserId, int type);
        void showEntryData(Entry entry);
        int calculateBalance();
        int sumAllEntries(const vector <Entry> &entries);
        vector <Entry> getEntriesFromSelectedPeriod(const vector<Entry>  &entries);
        void showTimePeriod();
        void showIncomes();
        void showExpenses();
        void showBalance();
        void showBalanceSheet();


};

#endif // INCOMEEXPENSEMANAGER_H
