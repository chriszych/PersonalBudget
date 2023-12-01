#ifndef USERSFILE_H
#define USERSFILE_H

#include <vector>
#include <cstdlib>

#include "User.h"
#include "Markup.h"
#include "CommonMethods.h"

using namespace std;

class UserFile {


public:

    UserFile(string fileName) {};

    void addUserToXmlFile();
    int getLastIdfromXmlFile();
    void displayAllUsers();
    vector <User> loadUsersFromXmlFile();
    void changeUserPasswordByIdInXmlFile(int findUserId, string newPassword);
    bool findLoginInXmlFile(string findLogin);
};
#endif
