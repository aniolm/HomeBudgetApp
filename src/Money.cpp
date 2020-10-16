#include "Money.h"


int Money::enterAmount()
{
    double amount;
    int amountInGrosze;
    cout << "Enter amount in PLN using following format(0.00): ";
    cin >> amount;
    amountInGrosze = static_cast<int>(amount * 100);
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

