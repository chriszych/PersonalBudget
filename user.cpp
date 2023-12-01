#include "User.h"

using namespace std;


#include "User.h"

using namespace std;

void User::setId(int newId) {
    if(newId >= 0) {
        id = newId;
    }
}

void User::setLogin(string login) {
    this -> login = login;
}

void User::setFirstname(string firstname) {
    this -> firstname = firstname;
}

void User::setLastname(string lastname) {
    this -> lastname = lastname;
}

void User::setPassword(string password) {
    this -> password = password;
}

int User::getId() {
    return id;
}
string User::getLogin() {
    return login;
}
string User::getFirstname() {
    return firstname;
}
string User::getLastname() {
    return lastname;
}
string User::getPassword() {
    return password;
}
