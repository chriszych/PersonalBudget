#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>

#include "BudgetItem.h"
#include "BudgetItemFile.h"

using namespace std;

class BudgetManager {

    BudgetItemFile budgetItemFile;
    const string INCOMES_FILE;
    const string EXPENSES_FILE;
    const int ID_LOGGED_USER;
    vector <BudgetItem> budgetItems, incomes, expenses;

public:

    BudgetManager(string incomesFileName, string expensesFileName, int idLoggedUser)
        : INCOMES_FILE(incomesFileName), EXPENSES_FILE(expensesFileName), ID_LOGGED_USER(idLoggedUser) {
    };

    void addIncome();
    void addExpense();
    void loadIncomesFromXmlFile();
    void loadExpensesFromXmlFile();
    void showBalanceSheet(string reportType);
    bool checkIfDateIsInRange(int dateToCheck, int dateStart, int dateFinish);

};

#endif
