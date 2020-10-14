#include <iostream>
#include "UserManager.h"
#include "IncomeExpenseManager.h"

using namespace std;

int main()
{
    UserManager userManager("UserFile.xml");
    //userManager.registerUser();
    //userManager.userLogin();
    //userManager.changeUserPassword();
    IncomeExpenseManager incomeExpenseManager("IncomeFile.xml","ExpenseFile.xml");

    return 0;
}
