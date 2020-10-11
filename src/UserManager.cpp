#include "UserManager.h"

UserManager::UserManager()
{
    //ctor
}

UserManager::~UserManager()
{
    //dtor
}

void UserManager::registerUser()
{
    User user = inputNewUserData();

    users.push_back(user);
    userFile.appendUserToFile(user);

    cout << endl << "User successfully registered." << endl<< endl;
    system("pause");

}

User UserManager::inputNewUserData()
{
    User user;

    user.setId(getNewUserId());

    cout << "Enter your name: ";
    user.setName(AuxMethods::changeFirstLetterToCapital(AuxMethods::getLine()));

    cout << "Enter your surname: ";
    user.setSurname(AuxMethods::changeFirstLetterToCapital(AuxMethods::getLine()));

    do
    {
        cout << endl << "Enter new username: ";
        user.setUsername(AuxMethods::getLine());
    } while (ifUsernameExists(user.getUsername()) == true);

    cout << "Enter password: ";
    user.setPassword(AuxMethods::getLine());

    return user;
}


int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}


bool UserManager::ifUsernameExists(string username)
{
    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getUsername() == username)
        {
            cout << endl << "Username already exists." << endl;
            return true;
        }
        else
            itr++;
    }
    return false;
}
