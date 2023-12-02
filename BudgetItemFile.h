#ifndef BUDGETITEMFILE_H
#define BUDGETITEMFILE_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "BudgetItem.h"
#include "CommonMethods.h"

using namespace std;

class BudgetItemFile{

    //const string INCOMES_FILE = "incomes.xml";
    //const string EXPENSES_FILE = "expenses.xml";
    int lastIncomeId;
    int lastExpenseId;


public:

     BudgetItemFile() {
        lastIncomeId = 0;
        lastExpenseId = 0;
    };

    int getLastIncomeId();
    int getLastExpenseId();
    void setLastIncomeId(int newLastIncomeId);
    void setLastExpenseId(int newLastExpenseId);

    void addBudgetItemToXmlFile(int idLoggedUser, string xmlFile);
    int getLastIdfromXmlFile(string xmlFile);
    vector <BudgetItem> loadBudgetItemsFromXmlFile(int ID_LOGGED_USER, string xmlFile);

};
#endif
