#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include "User.h"
#include "UserFile.h"
#include "AuxMethods.h"

using std::string;
using std::cin;
using std::cout;
using std::vector;

class UserManager
{
    public:
        UserManager();
        virtual ~UserManager();

        void registerUser();

    protected:

    private:
        vector <User> users;
        int loggedInUserId;
        UserFile userFile;
        User inputNewUserData();
        int getNewUserId();
        bool ifUsernameExists(string username);


};

#endif // USERMANAGER_H
