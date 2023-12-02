#include "PersonalBudget.h"

char PersonalBudget::selectMainMenuOption(){

    char menuSelection;

    system("cls");
    cout << "    >>>  MAIN MENU  <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add new user" << endl;
    cout << "2. Login user" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice (1,2,9): ";
    menuSelection = CommonMethods::readChar();

    return menuSelection;
}
char PersonalBudget::selectUserMenuOption(){

    char menuSelection;

    system("cls");
    cout << ">>>  PERSONAL BUDGET MENU  <<<" << endl;
    cout << "---------------------------------" << endl;
    cout << "Logged user : " << userManager.getFullUserNameById(userManager.getIdLoggedUser()) << endl;
    cout << "---------------------------------" << endl;
    cout << "1. Add new income" << endl;
    cout << "2. Add new expense" << endl;
    cout << "3. Current month balance sheet" << endl;
    cout << "4. Previous month balance sheet" << endl;
    cout << "5. Selected period balance sheet" << endl;
    cout << "---------------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------------" << endl;
    cout << "Your choice (1-5,7,8): ";
    menuSelection = CommonMethods::readChar();

    return menuSelection;
}

void PersonalBudget::registerUser(){
    userManager.registerUser();
}

void PersonalBudget::loginUser(){
    userManager.loginUser();

    if(userManager.isUserLoggedIn()) {
        budgetManager = new BudgetManager(INCOMES_FILE, EXPENSES_FILE, userManager.getIdLoggedUser());
    }
}

bool PersonalBudget::isUserLoggedIn(){
    return userManager.isUserLoggedIn();
}
void PersonalBudget::changeLoggedUserPassword(){
     userManager.changeLoggedUserPassword();
}
void PersonalBudget::logoutCurrentUser(){
     userManager.logoutCurrentUser();
}

void PersonalBudget::addIncome(){
    budgetManager -> addIncome();
}
void PersonalBudget::addExpense(){
    budgetManager -> addExpense();
}
void PersonalBudget::showBalanceSheet(string timePeriod){
    budgetManager -> loadIncomesFromXmlFile();
    budgetManager -> loadExpensesFromXmlFile();
    budgetManager -> showBalanceSheet(timePeriod);
}


