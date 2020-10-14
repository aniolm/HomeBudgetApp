#ifndef INCOMEEXPENSEMANAGER_H
#define INCOMEEXPENSEMANAGER_H
#include "Entry.h"
#include "IncomeExpenseFile.h"
#include <vector>

using std::vector;

class IncomeExpenseManager
{
    public:
        IncomeExpenseManager(string incomeFileName, string expenseFileName);


    protected:

    private:
        vector <Entry> incomes;
        vector <Entry> expenses;
        IncomeExpenseFile incomeFile;
        IncomeExpenseFile expenseFile;

};

#endif // INCOMEEXPENSEMANAGER_H
