#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>

#include "BudgetManager.h"
//#include "UserManager.h"

using namespace std;

class Budget {

    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOMES_FILE;
    const string EXPENSES_FILE;

public:

    Budget(string userFileName, string incomesFileName, string expensesFileName)
        : userManager(userFileName), INCOMES_FILE(incomesFileName), EXPENSES_FILE(expensesFileName) {
        budgetManager = NULL;
    };
    ~Budget() {
        delete budgetManager;
        budgetManager = NULL;
    };

//    void registerUser();
//    void showAllUsers();
//    void loginUser();
//    void changeLoggedUserPassword();
//    void logoutCurrentUser();
//    bool isUserLoggedIn();

    char selectMainMenuOption();
    char selectUserMenuOption();

//    void addPerson();
//    void searchPersonByFirstName();
//    void searchPersonByLastName();
//    void showAllPersons();
//    void deletePerson();
//    void modifyPerson();
};
#endif
