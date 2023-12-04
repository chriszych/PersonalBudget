#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include <cstdlib>

#include "BudgetManager.h"
#include "UserManager.h"

using namespace std;

class PersonalBudget {

    UserManager userManager;
    const int ID_LOGGED_USER = 0;
    const string INCOMES_FILE;
    const string EXPENSES_FILE;
    BudgetManager *budgetManager;

public:

    PersonalBudget(string userFileName, string incomesFileName, string expensesFileName)
        : userManager(userFileName), INCOMES_FILE(incomesFileName), EXPENSES_FILE(expensesFileName) {
        budgetManager = NULL;
    };
    ~PersonalBudget() {
        delete budgetManager;
        budgetManager = NULL;
    };

    void loginUser();
    void changeLoggedUserPassword();
    void logoutCurrentUser();
    bool isUserLoggedIn();

    char selectMainMenuOption();
    char selectUserMenuOption();

    void registerUser();
    void addIncome();
    void addExpense();
    void showBalanceSheet(string timePeriod);

};
#endif
