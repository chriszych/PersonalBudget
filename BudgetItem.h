#ifndef BUDGETITEM_H
#define BUDGETITEM_H

#include <iostream>

using namespace std;

class BudgetItem {

    int id;
    int userId;
    string description;
    int date;
    double amount;

public:

    BudgetItem(int id = 0, int userId = 0, string description = "", int date = 0, double amount = 0) {
        this -> id = id;
        this -> userId = userId;
        this -> description = description;
        this -> date = date;
        this -> amount = amount;
    };

    int getId();
    int getUserId();
    string getDescription();
    int getDate();
    double getAmount();

    void setId(int newId);
    void setUserId(int newUserId);
    void setDescription(string newDescription);
    void setDate(int newDate);
    void setAmount(double newAmount);
};
#endif
