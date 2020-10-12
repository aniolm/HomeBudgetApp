#include <iostream>
#include "UserManager.h"

using namespace std;

int main()
{
    UserManager userManager("UserFile.xml");
    userManager.registerUser();
    return 0;
}
