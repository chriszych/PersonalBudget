#include "UserManager.h"

int UserManager::getIdLoggedUser() {
    return idLoggedUser;
}
void UserManager::setIdLoggedUser(int newIdLoggedUser) {
    idLoggedUser = newIdLoggedUser;
}

void UserManager::registerUser() {
    userFile.addUserToXmlFile();
    users = userFile.loadUsersFromXmlFile();
}
void UserManager::showAllUsers() {
    cout << "List of registered users: " << endl;
    for (size_t i=0; i < users.size(); ++i) {

        cout << "(" << users[i].getId() << "). " << users[i].getLogin() << " : " << users[i].getPassword() << " - " << users[i].getFirstname() <<" " << users[i].getLastname() << endl;
    }
}
int UserManager::loginUser() {

        string login = "", password = "";

    cout << "Logging user: " << endl;
    cout << "Enter login: ";
    login = CommonMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int attemptNumber = 3; attemptNumber > 0; --attemptNumber) {
                cout << "Attempt: " << 4 - attemptNumber << "/3. Enter password: ";
                password = CommonMethods::readLine();

                if (itr -> getPassword() == password) {
                    setIdLoggedUser(itr -> getId());
                    idLoggedUser = itr -> getId();
                     cout << "User : " << itr -> getFirstname() << " " << itr -> getLastname() << " (" << itr -> getId() << ") logged in successfully." << endl;
                     system("pause");
                    return idLoggedUser;
                }
            }
            cout << "You have entered 3 times wrong password." << endl;
            system("pause");
            return 0;
        }
        ++itr;
    }
    cout << "The user name was not found. Try login with correct user name" << endl;
    system("pause");
    return 0;
}

void UserManager::changeLoggedUserPassword() {
    string newPassword = "";
    int foundUserId;

    cout << "Changing user password: " << endl;
    cout << "Enter new Password: ";
    newPassword = CommonMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); ++itr) {
        if (itr -> getId() == getIdLoggedUser()) {
            foundUserId = itr -> getId();
            itr -> setPassword(newPassword);
            cout << "Password changed successfully." << endl << endl;
            system("pause");
        }
    }
   userFile.changeUserPasswordByIdInXmlFile(foundUserId, newPassword);
}
void UserManager::logoutCurrentUser() {
    setIdLoggedUser(0);
}
bool UserManager::isUserLoggedIn() {
    if(getIdLoggedUser() > 0)
        return true;
    else
        return false;
}

string UserManager::getFullUserNameById(int userId){
    string fullname;
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); ++itr) {
        if (itr -> getId() == userId) {

            fullname = itr -> getFirstname() + " " + itr -> getLastname();
        }
    }
    return fullname;
}
