#ifndef INCOMEEXPENSEFILE_H
#define INCOMEEXPENSEFILE_H

#include <iostream>
#include "Markup.h"
#include "User.h"
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class IncomeExpenseFile
{
    public:
        IncomeExpenseFile(string fileName);


    protected:

    private:
        const string FILE_NAME;

};

#endif // INCOMEEXPENSEFILE_H
