#ifndef BUDGETITEMFILE_H
#define BUDGETITEMFILE_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "BudgetItem.h"
#include "ReadAndConvertMethods.h"
#include "DateMethods.h"

using namespace std;

class BudgetItemFile{

    int lastIncomeId;
    int lastExpenseId;

    int getLastIdfromXmlFile(string xmlFile);


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
    vector <BudgetItem> loadBudgetItemsFromXmlFile(int ID_LOGGED_USER, string xmlFile);

};
#endif
