#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UserFile.h"
#include "ReadAndConvertMethods.h"

using namespace std;

class UserManager {

    int idLoggedUser;
    vector <User> users;
    UserFile userFile;

    User enterNewUserData();
    int getNewUserId();
    bool checkIfLoginExist(string login);

public:

    UserManager(string fileName) : userFile(fileName) {
        idLoggedUser = 0;
        users = userFile.loadUsersFromXmlFile();
    };

    int getIdLoggedUser();
    void setIdLoggedUser(int newIdLoggedUser);

    void registerUser();
    int loginUser();

    void changeLoggedUserPassword();
    void logoutCurrentUser();
    bool isUserLoggedIn();
    string getFullUserNameById(int userId);
};
#endif
