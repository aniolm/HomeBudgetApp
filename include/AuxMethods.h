#ifndef AUXMETHODS_H
#define AUXMETHODS_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class AuxMethods
{
    public:
        AuxMethods();
        virtual ~AuxMethods();
        static string getLine();
        static string changeFirstLetterToCapital(string text);
        static bool inputYesNo();
        static char inputCharacter();

    protected:

    private:
};

#endif // AUXMETHODS_H
