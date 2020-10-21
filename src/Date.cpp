#include "Date.h"



time_t Date::getCurrentDate()
{
    time_t date = time(NULL);
    return date;
}

int Date::getCurrentYear()
{
    time_t date = getCurrentDate();
    struct tm* now;

    now = localtime(&date);
    return  (now->tm_year + 1900);

}

int Date::getCurrentMonth()
{
    time_t date = getCurrentDate();
    struct tm* now;

    now = localtime(&date);
    return  (now->tm_mon + 1);

}

int Date::getPreviousMonth()
{
    if (getCurrentMonth()==1)
    {
        return  12;
    }
    else
    {
        return (getCurrentMonth()-1);
    }
}

int Date::getPreviousYear()
{
    if (getCurrentMonth()==1)
    {
        return  getCurrentYear()-1;
    }
    else
    {
        return (getCurrentYear());
    }
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
    ss >> get_time(&t, "%d-%m-%Y");
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

int  Date::getNumberOfDays(int month, int year)
{
	if( month == 2)
	{
		if((year%400==0) || (year%4==0 && year%100!=0))
			return 29;
		else
			return 28;
	}
	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
	||month == 10 || month==12)
		return 31;
	else
		return 30;
}
