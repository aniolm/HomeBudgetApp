#ifndef DATE_H
#define DATE_H
#include <ctime>
#include <sstream>
#include <iostream>
#include <iomanip>

using std::stringstream;
using std::cin;
using std::cout;
using std::string;
using std::endl;

class Date
{
    public:

        static time_t getCurrentDate();
        static time_t enterDate();
        static string convertToString(time_t date);

    protected:

    private:
};

#endif // DATE_H
