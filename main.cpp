#include <iostream>
#include "UserManager.h"

using namespace std;

int main()
{
    UserManager userManager("UserFile.xml");
    userManager.registerUser();
    userManager.userLogin();
    return 0;
}
