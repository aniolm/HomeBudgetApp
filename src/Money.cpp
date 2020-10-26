#include "Money.h"


int Money::enterAmount()
{
    double amount;
    int amountInGrosze;
    cout << "Enter the amount in PLN using the following format(0.00): ";
    cin >> amount;
    amountInGrosze = static_cast<int>(amount * 100);
    cout<<endl;
    return amountInGrosze;
}




string Money::convertToString(int amountInGrosze)
{
    string zlotys = std::to_string(std::abs(amountInGrosze / 100));
    string grosze = std::to_string(std::abs(amountInGrosze % 100));

    if (grosze.size() == 1)
    {
        grosze = "0" + grosze;
    }

    string sign = amountInGrosze < 0 ? "-" : "";

    // TODO: Add comma thousands separator

    return sign  + zlotys + "." + grosze + "PLN";
}

