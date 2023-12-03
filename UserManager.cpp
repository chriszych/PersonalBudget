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

int UserManager::loginUser() {

    string login = "", password = "";

    cout << "Logging user/";
    cout << "Enter login: ";
    login = ReadAndConvertMethods::readLine();
    for (int attemptNumber = 3; attemptNumber > 0; --attemptNumber) {
        cout << "Logging user/";
        cout << "Attempt: " << 4 - attemptNumber << "/3. Enter password: ";
        password = ReadAndConvertMethods::readLine();

        vector <User>::iterator itr = users.begin();
        while (itr != users.end()) {

            if ((itr -> getLogin() == login) && (itr -> getPassword() == password)) {
                setIdLoggedUser(itr -> getId());
                idLoggedUser = itr -> getId();
                cout << "Logging user/";
                cout << "Logging " << itr -> getFirstname() << " " << itr -> getLastname() << " (" << itr -> getId() << ") in. Please wait.." << endl;
                Sleep(3000);
                return idLoggedUser;
            }
            ++itr;
        }

    }
    cout << "Logging user/";
    cout << "Invalid user name or password. Try to login in again." << endl;
    system("pause");
    return 0;
}

void UserManager::changeLoggedUserPassword() {
    string newPassword = "";
    int foundUserId;

    cout << "Changing user password/";
    cout << "Enter new Password: ";
    newPassword = ReadAndConvertMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); ++itr) {
        if (itr -> getId() == getIdLoggedUser()) {
            foundUserId = itr -> getId();
            itr -> setPassword(newPassword);
            cout << "Changing user password/";
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

string UserManager::getFullUserNameById(int userId) {
    string fullname;
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); ++itr) {
        if (itr -> getId() == userId) {

            fullname = itr -> getFirstname() + " " + itr -> getLastname();
        }
    }
    return fullname;
}
