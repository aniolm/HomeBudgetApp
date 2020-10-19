#include "Date.h"



time_t Date::getCurrentDate()
{
    time_t t1 = time(NULL);
    return t1;
}

time_t Date::enterDate()
{
    tm t = {};
    time_t timestamp;
    string date = "";

    cout<<"Enter date in the following format (dd-mm-yyyy):";
    cin>>date;
    stringstream ss;
    ss << date;
    ss >> std::get_time(&t, "%d-%m-%Y");
    timestamp = mktime(&t);
    return timestamp;
}

string Date::convertToString(time_t date)
{
    string dateInString;
    struct tm* now;
    stringstream ss;
    now = localtime(&date);
    ss << now->tm_mday << '-'
    << (now->tm_mon + 1) << '-'
    << (now->tm_year + 1900);
    ss>>dateInString;
    return dateInString;

}
