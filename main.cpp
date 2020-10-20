#include <iostream>
#include "HomeBudgetApp.h"


using namespace std;

int main()
{
    //UserManager userManager("UserFile.xml");
    //userManager.registerUser();
    //userManager.userLogin();
    //userManager.changeUserPassword();
    // incomeExpenseManager("IncomeFile.xml","ExpenseFile.xml");

    //incomeExpenseManager.addEntry(userManager.getLoggedInUserId(),0);
    //incomeExpenseManager.addEntry(userManager.getLoggedInUserId(),1);

    //incomeExpenseManager.showBalanceSheetFromActualMonth();



    HomeBudgetApp app("UserFile.xml", "IncomeFile.xml", "ExpenseFile.xml");
    return 0;

}
