#include <iostream>
#include "UserManager.h"
#include "IncomeExpenseManager.h"
#include "Date.h"

using namespace std;

int main()
{
    UserManager userManager("UserFile.xml");
    //userManager.registerUser();
    userManager.userLogin();
    //userManager.changeUserPassword();
    IncomeExpenseManager incomeExpenseManager("IncomeFile.xml","ExpenseFile.xml");

    //incomeExpenseManager.addEntry(userManager.getLoggedInUserId(),0);
    //incomeExpenseManager.addEntry(userManager.getLoggedInUserId(),1);

    incomeExpenseManager.showBalanceSheetFromActualMonth();
    return 0;
}
