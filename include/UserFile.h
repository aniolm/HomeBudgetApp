#ifndef USERFILE_H
#define USERFILE_H
#include "Markup.h"
#include "User.h"

using namespace std;

class UserFile
{
    public:
        UserFile();
        virtual ~UserFile();
        void appendUserToFile(User);

    protected:

    private:
};

#endif // USERFILE_H
