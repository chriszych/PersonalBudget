#ifndef USERSFILE_H
#define USERSFILE_H

#include <vector>
#include <cstdlib>

#include "User.h"
#include "Markup.h"
#include "ReadAndConvertMethods.h"

using namespace std;

class UserFile {

    const string USERS_FILE;
    int getLastIdfromXmlFile();
    bool findLoginInXmlFile(string findLogin);

public:

    UserFile(string usersFileName) : USERS_FILE(usersFileName){};

    void addUserToXmlFile();
    vector <User> loadUsersFromXmlFile();
    void changeUserPasswordByIdInXmlFile(int findUserId, string newPassword);

};
#endif
