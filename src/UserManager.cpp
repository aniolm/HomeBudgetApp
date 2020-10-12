#include "UserManager.h"
UserManager::UserManager(string userFileName): userFile(userFileName)
{
    loggedInUserId = 0;
    loadUsersFromFile();
}

void UserManager::loadUsersFromFile()
{
    users = userFile.loadUsersFromFile();
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

void  UserManager::userLogin()
{
    User user;

    string username = "", password = "";

    cout << endl << "Enter username: ";
    username = AuxMethods::getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getUsername() == username)
        {
            for (int attemptsLeft = 3; attemptsLeft> 0; attemptsLeft--)
            {
                cout << "Enter password (attempts left: " << attemptsLeft << "): ";
                password = AuxMethods::getLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Login successful." << endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getId();
                    return;
                }
            }
            cout << "Invalid password." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Username does not exist." << endl << endl;
    system("pause");
    return;
}
