#ifndef HOMEBUDGETAPP_H
#define HOMEBUDGETAPP_H
#include "UserManager.h"
#include "IncomeExpenseManager.h"


class HomeBudgetApp
{
    public:
        HomeBudgetApp(string userFileName,string incomeFileName, string expenseFileName);
        ~HomeBudgetApp();
        void registerUser();
        void loginUser();

        void addIncome();
        void addExpense();
        void showBalanceSheetFromActualMonth();
        void showBalanceSheetFromPreviousMonth();
        void showBalanceSheetFromGivenPeriod();
        void logoutUser();
        void changeUserPassword();
        char selectMainMenuOption();
        char selectInitialMenuOption();
        bool isUserLoggedIn();

    protected:

    private:
        UserManager userManager;
        IncomeExpenseManager *incomeExpenseManager;
        const string INCOME_FILE_NAME;
        const string EXPENSE_FILE_NAME;


};

#endif // HOMEBUDGETAPP_H
