#ifndef AUXMETHODS_H
#define AUXMETHODS_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using std::string;
using std::cin;

class AuxMethods
{
    public:
        AuxMethods();
        virtual ~AuxMethods();
        static string getLine();
        static string changeFirstLetterToCapital(string text);

    protected:

    private:
};

#endif // AUXMETHODS_H
