#include <iostream>
#include "HomeBudgetApp.h"


using namespace std;

int main()
{

    HomeBudgetApp app("UserFile.xml", "IncomeFile.xml", "ExpenseFile.xml");

    char selection;


    while (true)
    {
        if (app.isUserLoggedIn() == false)
        {
          selection = app.selectInitialMenuOption();

            switch (selection)
            {
            case '1':
                app.registerUser();
                break;
            case '2':
                app.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Invalid number." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {


            selection = app.selectMainMenuOption();

            switch (selection)
            {
            case '1':
                app.addIncome();
                break;
            case '2':
                app.addExpense();
                break;
            case '3':
                app.showBalanceSheetFromActualMonth();
                break;
            case '4':
                app.showBalanceSheetFromPreviousMonth();
                break;
            case '5':
                app.showBalanceSheetFromGivenPeriod();
                break;

            case '7':
                app.changeUserPassword();
                break;
            case '8':
                app.logoutUser();

                break;
            }
        }
    }
    return 0;

}
