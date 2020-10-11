#include "AuxMethods.h"

AuxMethods::AuxMethods()
{
    //ctor
}

AuxMethods::~AuxMethods()
{
    //dtor
}

string AuxMethods:: getLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

string AuxMethods::changeFirstLetterToCapital(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
