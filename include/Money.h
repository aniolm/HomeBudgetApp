#ifndef MONEY_H
#define MONEY_H
#include<iostream>

using std::cin;
using std::string;
using std::cout;


class Money
{
    public:
        static int enterAmount();
        static string convertToString(int amountInGrosze);

    protected:

    private:
};

#endif // MONEY_H
