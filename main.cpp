#include <iostream>
#include "UserFile.h"
#include "UserManager.h"
#include "PersonalBudget.h"

using namespace std;




int main() {

    char menuSelection;

    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    while (true) {
        if (!personalBudget.isUserLoggedIn()) {
            menuSelection = personalBudget.selectMainMenuOption();

            switch (menuSelection) {
            case '1': personalBudget.registerUser(); break;
            case '2': personalBudget.loginUser(); break;
            case '9': exit(0); break;
            default:
                cout << endl << "No such menu option." << endl << endl;
                system("pause");
                break;
            }
        } else {

            menuSelection = personalBudget.selectUserMenuOption();

            switch (menuSelection) {
            case '1': personalBudget.addIncome(); break;
            case '2': personalBudget.addExpense(); break;
            case '3': personalBudget.showBalanceSheet("currentMonth"); break;
            case '4': personalBudget.showBalanceSheet("previousMonth"); break;
            case '5': personalBudget.showBalanceSheet("customPeriod"); break;
            case '7': personalBudget.changeLoggedUserPassword(); break;
            case '8': personalBudget.logoutCurrentUser(); break;

            }
        }
    }

    return 0;
}


