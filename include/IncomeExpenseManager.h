#ifndef INCOMEEXPENSEMANAGER_H
#define INCOMEEXPENSEMANAGER_H
#include "Entry.h"
#include "IncomeExpenseFile.h"
#include "AuxMethods.h"
#include "Date.h"
#include "Money.h"
#include <vector>
#include <iomanip>

using std::vector;
using std::setw;
using std::left;
using std::right;

class IncomeExpenseManager
{
    public:
        IncomeExpenseManager(string incomeFileName, string expenseFileName);
        void addEntry(int loggedInUserId, int type);
        Entry inputNewEntryData(int loggedInUserId, int type);
        void showAllIncomes();
        void showAllExpenses();
        void showBalance();




    protected:

    private:
        vector <Entry> incomes;
        vector <Entry> expenses;
        IncomeExpenseFile incomeFile;
        IncomeExpenseFile expenseFile;

        void showEntryData(Entry entry);
        int calculateBalance();
        int sumAllEntries(const vector <Entry> &entries);

};

#endif // INCOMEEXPENSEMANAGER_H
