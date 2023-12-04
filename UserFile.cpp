#include "User.h"
#include "UserFile.h"
#include "Markup.h"

void UserFile::addUserToXmlFile() {

    CMarkup xml;
    bool fileExists = xml.Load(USERS_FILE);
    string login, password, firstname, lastname;

    int userId = getLastIdfromXmlFile() + 1;

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    cout << "Adding new user/";
    cout << "Enter login: ";
    login = ReadAndConvertMethods::readLine();

    if(!findLoginInXmlFile(login)) {
        cout << "Adding new user/";
        cout << "Enter firstname: ";
        firstname = ReadAndConvertMethods::readLine();
        cout << "Adding new user/";
        cout << "Enter lastname: ";
        lastname = ReadAndConvertMethods::readLine();
        cout << "Adding new user/";
        cout << "Enter password: ";
        password = ReadAndConvertMethods::readLine();

        xml.ResetPos();
        xml.FindElem();

        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();

        xml.AddElem("UserId", userId);
        xml.AddElem("Firstname", firstname);
        xml.AddElem("Lastname", lastname);
        xml.AddElem("Login", login);
        xml.AddElem("Password", password);

        xml.Save(USERS_FILE);

        cout << "Adding new user/";
        cout << "User " << firstname << " " << lastname << " with ID: " << userId << " added successfully." << endl;
        system("pause");


    } else {
        cout << "Adding new user/";
        cout << "Login already in use. Select other one, please." << endl;
        system("pause");
    }
}

int UserFile::getLastIdfromXmlFile() {

    CMarkup xml;
    xml.Load(USERS_FILE);

    int maxUserId = 0;

    xml.ResetPos();
    xml.FindElem(); // Find USERS element
    xml.IntoElem(); // inside USERS

    while ( xml.FindElem("User") ) {

        xml.IntoElem();
        xml.FindElem( "UserId" );
        int userId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.ResetMainPos();

        if(userId > maxUserId) {
            maxUserId = userId;
        }

        xml.OutOfElem();
    }

    return maxUserId;
}

bool UserFile::findLoginInXmlFile(string findLogin) {

    bool foundHim = false;

    CMarkup xml;
    xml.Load(USERS_FILE);

    xml.ResetPos();
    xml.FindElem(); // Find USERS element
    xml.IntoElem(); // inside USERS

    while ( xml.FindElem("User") ) {

        xml.IntoElem();
        xml.FindElem("Login");
        MCD_STR userLogin = xml.GetData();
        xml.ResetMainPos();

        if (userLogin == findLogin) {
            foundHim = true;
            break;
        }
        xml.OutOfElem();
    }

    return foundHim;
}

vector <User> UserFile::loadUsersFromXmlFile() {

    CMarkup xml;
    xml.Load(USERS_FILE);

    vector <User> users;
    User user;

    xml.ResetPos();
    xml.FindElem(); // Find USERS element
    xml.IntoElem(); // inside USERS

    while ( xml.FindElem("User") ) {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        int userId = atoi(MCD_2PCSZ(xml.GetData()));
        user.setId(userId);
        xml.ResetMainPos();

        xml.FindElem("Login");
        MCD_STR login = xml.GetData();
        user.setLogin(login);
        xml.ResetMainPos();

        xml.FindElem("Password");
        MCD_STR userPass = xml.GetData();
        user.setPassword(userPass);
        xml.ResetMainPos();

        xml.FindElem("Firstname");
        MCD_STR firstname = xml.GetData();
        user.setFirstname(firstname);
        xml.ResetMainPos();

        xml.FindElem("Lastname");
        MCD_STR lastname = xml.GetData();
        user.setLastname(lastname);
        xml.ResetMainPos();

        xml.OutOfElem();
        users.push_back(user);
    }

    return users;
}

void UserFile::changeUserPasswordByIdInXmlFile(int findUserId, string newPassword) {

    CMarkup xml;
    xml.Load(USERS_FILE);

    bool foundHim = false;

    xml.ResetPos();
    xml.FindElem(); // Find USERS element
    xml.IntoElem(); // inside USERS

    while ( xml.FindElem("User") ) {

        xml.IntoElem();
        xml.FindElem( "UserId" );
        int userId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.ResetMainPos();

        if (userId == findUserId) {

            xml.ResetMainPos();
            xml.FindElem("Password");

            if(xml.SetData(newPassword)) {

                foundHim = true;
                break;
            }
        } else {
            foundHim = false;
        }
        xml.OutOfElem();

    }
    if (!foundHim) {
        cout << "User not found" << endl;
    }
    xml.Save(USERS_FILE);
}
