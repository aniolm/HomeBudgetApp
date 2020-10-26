#include "HomeBudgetApp.h"

HomeBudgetApp::HomeBudgetApp(string userFileName,string incomeFileName, string expenseFileName): INCOME_FILE_NAME (incomeFileName), EXPENSE_FILE_NAME(expenseFileName), userManager(userFileName)
{
    incomeExpenseManager = NULL;
}

HomeBudgetApp::~HomeBudgetApp()
{
    delete incomeExpenseManager;
    incomeExpenseManager = NULL;
}

void HomeBudgetApp::registerUser()
{
    userManager.registerUser();
}

void HomeBudgetApp::loginUser()
{
    userManager.userLogin();
    if (userManager.getLoggedInUserId()>0)
    {
            incomeExpenseManager = new IncomeExpenseManager(INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoggedInUserId());
    }

}

void HomeBudgetApp::logoutUser()
{
    userManager.setLoggedInUserId(0);
    delete incomeExpenseManager;
    incomeExpenseManager = NULL;
}


 void HomeBudgetApp::addIncome()
 {
     incomeExpenseManager->addEntry(userManager.getLoggedInUserId(), 0);
 }

void HomeBudgetApp::addExpense()
{
    incomeExpenseManager->addEntry(userManager.getLoggedInUserId(), 1);
}

void HomeBudgetApp::showBalanceSheetFromActualMonth()
{
    incomeExpenseManager->showBalanceSheetFromActualMonth();
}

void HomeBudgetApp::showBalanceSheetFromPreviousMonth()
{
    incomeExpenseManager->showBalanceSheetFromPreviousMonth();
}

void HomeBudgetApp::showBalanceSheetFromGivenPeriod()
{
    incomeExpenseManager->showBalanceSheetFromGivenPeriod();
}

void HomeBudgetApp::changeUserPassword()
{
    userManager.changeUserPassword();
}

char HomeBudgetApp::selectMainMenuOption()
{
    char selection;

    system("cls");
    cout << ">>> HOME BUDGET APP 1.0 <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show balance (current month)" << endl;
    cout << "4. Show balance (previous month)" << endl;
    cout << "5. Show balance (selected period)" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter number: ";
    selection = AuxMethods::inputCharacter();

    return selection;
}
char HomeBudgetApp::selectInitialMenuOption()
{
    char selection;

    system("cls");
    cout << ">>> HOME BUDGET APP 1.0 <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. User registration" << endl;
    cout << "2. User login" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter number: ";
    selection = AuxMethods::inputCharacter();

    return selection;
}

bool HomeBudgetApp::isUserLoggedIn()
{
    if (userManager.getLoggedInUserId()>0)
        return true;
    else
        return false;
}
