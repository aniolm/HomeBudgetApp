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
using std::get_time;

class Date
{
    public:

        static time_t getCurrentDate();
        static time_t enterDate();
        static string convertToString(time_t date);
        static int getCurrentYear();
        static int getCurrentMonth();
        static int getPreviousMonth();
        static int getPreviousYear();
        static int getNumberOfDays(int month, int year);

    protected:

    private:
};

#endif // DATE_H
