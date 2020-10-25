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

bool AuxMethods::inputYesNo()
{
    string input = "";
    char character  = {0};
    cin.sync();
    while (true)
    {
        getline(cin, input);

        if ((input.length() == 1)&&((input[0] == 'y')||(input[0] == 'n')))
        {
            if(input[0] == 'y')
                return true;
            else
                return false;
        }
        else
        {
            cout << "Invalid character. Please enter 'y' or 'n'."<< endl;
        }

    }
}

char AuxMethods::inputCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "Invalid character. Please choose again." << endl;
    }
    return character;
}
