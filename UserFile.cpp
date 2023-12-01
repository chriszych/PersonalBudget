#include "User.h"
#include "UserFile.h"
#include "Markup.h"

void UserFile::addUserToXmlFile() {

    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );
    string login, password, firstname, lastname;

    int userId = getLastIdfromXmlFile() + 1;

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    cout << "Enter login: ";
    login = CommonMethods::readLine();

    if(!findLoginInXmlFile(login)) {
        cout << "Enter firstname: ";
        firstname = CommonMethods::readLine();
        cout << "Enter lastname: ";
        lastname = CommonMethods::readLine();
        cout << "Enter password: ";
        password = CommonMethods::readLine();

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

        xml.Save("users.xml");
    } else {
        cout << "Login already in use. Select other one, please." << endl;
        system("pause");
    }


}

int UserFile::getLastIdfromXmlFile() {

    CMarkup xml;
    xml.Load( "users.xml" );

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

void insertUserToXmlFile(CMarkup &xml, bool fileExists, int userId, string userLogin, string userPass) {


    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.ResetPos();
    xml.FindElem(); // Find USERS element
    xml.IntoElem(); // inside USERS
    xml.InsertElem("User");
    xml.IntoElem();
    xml.InsertElem("Password", userPass);
    xml.InsertElem("Login", userLogin);
    xml.InsertElem("UserId", userId);

    xml.Save("users.xml");

}

bool UserFile::findLoginInXmlFile(string findLogin) {

    bool foundHim = false;

    CMarkup xml;
    xml.Load( "users.xml" );

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

void deleteUserByIdInXmlFile(CMarkup &xml, int findUserId) {

    bool foundHim = false;

    xml.ResetPos();
    xml.FindElem(); // Find USERS element
    xml.IntoElem(); // inside USERS

    while ( xml.FindElem("User") ) {


        xml.IntoElem();
        xml.FindElem("Login");
        MCD_STR userLogin = xml.GetData();
        xml.ResetMainPos();

        xml.FindElem( "UserId" );
        int userId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.ResetMainPos();

        if (userId == findUserId) {
            xml.OutOfElem();
            if(xml.RemoveElem()) {
                cout << "Found user: " << userId << "." << userLogin << " was deleted!" << endl;
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

    system("pause");
    xml.Save("users.xml");
}

void deleteAllInXmlFile(CMarkup &xml) {

    bool deleteResult = false;

    xml.ResetPos();

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem() ) {

        deleteResult = xml.RemoveElem();
    }
    cout << "Result: " << deleteResult << endl;
    xml.Save("users.xml");

}

void changeUserLoginByIdInXmlFile(CMarkup &xml, int findUserId, string newLogin) {

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
            xml.FindElem("Login");
            MCD_STR userLogin = xml.GetData();

            if(xml.SetData(newLogin)) {
                cout << "Found user: " << userId << "." << userLogin << " was modified!" << endl;
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

    system("pause");
    xml.Save("users.xml");
}

void UserFile::displayAllUsers() {

    CMarkup xml;
    xml.Load( "users.xml" );

    xml.ResetPos();
    xml.FindElem(); // Find USERS element
    xml.IntoElem(); // inside USERS

    while ( xml.FindElem("User") ) {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        int userId = atoi(MCD_2PCSZ(xml.GetData()));
        cout << userId;
        xml.ResetMainPos();

        xml.FindElem("Login");
        MCD_STR login = xml.GetData();
        cout << ". " << login;
        xml.ResetMainPos();

        xml.FindElem("Password");
        MCD_STR userPass = xml.GetData();
        cout << ":" << userPass;
        xml.ResetMainPos();

        xml.FindElem("Firstname");
        MCD_STR firstname = xml.GetData();
        cout << " - " << firstname;
        xml.ResetMainPos();

        xml.FindElem("Lastname");
        MCD_STR lastname = xml.GetData();
        cout << " " << lastname << endl;
        xml.ResetMainPos();

        xml.OutOfElem();
    }
}
vector <User> UserFile::loadUsersFromXmlFile() {

    CMarkup xml;
    xml.Load( "users.xml" );

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
    xml.Load( "users.xml" );

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

    xml.Save("users.xml");
}
