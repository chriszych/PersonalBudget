#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {

    int id;
    string firstname;
    string lastname;
    string login;
    string password;

public:

    int getId();
    string getFirstname();
    string getLastname();
    string getLogin();
    string getPassword();

    void setId(int newId);
    void setFirstname(string newFirstname);
    void setLastname(string newLastname);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
};
#endif
