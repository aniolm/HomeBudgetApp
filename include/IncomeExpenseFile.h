#ifndef INCOMEEXPENSEFILE_H
#define INCOMEEXPENSEFILE_H

#include <iostream>
#include "Markup.h"
#include "User.h"
#include "Entry.h"
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class IncomeExpenseFile
{
    public:
        IncomeExpenseFile(string fileName);
        //void getLastEntryIdFromFile(int loggedInUserId);
        void appendEntryToFile(Entry entry);
        vector <Entry> loadEntriesFromFile(int loggedInUserId);


    protected:

    private:
        const string FILE_NAME;



};

#endif // INCOMEEXPENSEFILE_H
