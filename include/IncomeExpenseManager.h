#ifndef INCOMEEXPENSEMANAGER_H
#define INCOMEEXPENSEMANAGER_H
#include "Entry.h"
#include "IncomeExpenseFile.h"
#include "AuxMethods.h"
#include "Date.h"
#include "Money.h"
#include <vector>

using std::vector;

class IncomeExpenseManager
{
    public:
        IncomeExpenseManager(string incomeFileName, string expenseFileName);
        void addEntry(int loggedInUserId, int type);
        Entry inputNewEntryData(int loggedInUserId, int type);



    protected:

    private:
        vector <Entry> incomes;
        vector <Entry> expenses;
        IncomeExpenseFile incomeFile;
        IncomeExpenseFile expenseFile;


};

#endif // INCOMEEXPENSEMANAGER_H
