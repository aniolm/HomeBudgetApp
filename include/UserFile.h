#ifndef USERFILE_H
#define USERFILE_H
#include "Markup.h"
#include "User.h"
#include <vector>

using namespace std;

class UserFile
{
    public:
        UserFile(string userFileName);
        void appendUserToFile(User);
        vector <User> loadUsersFromFile();
        void updateUserData(string field , string newData, int userId);

    protected:

    private:
        const string USER_FILE_NAME;
};

#endif // USERFILE_H
