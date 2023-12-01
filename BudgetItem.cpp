   #include "BudgetItem.h"

    int BudgetItem::getId(){
        return id;
    }
    int BudgetItem::getUserId(){
        return userId;
    }
    string BudgetItem::getDescription(){
        return description;
    }
    int BudgetItem::getDate(){
        return date;
    }
    double BudgetItem::getAmount(){
        return amount;
    }

    void BudgetItem::setId(int newId){
        id = newId;
    }
    void BudgetItem::setUserId(int newUserId){
        userId = newUserId;
    }
    void BudgetItem::setDescription(string newDescription){
        description = newDescription;
    }
    void BudgetItem::setDate(int newDate){
        date = newDate;
    }
    void BudgetItem::setAmount(double newAmount){
        amount = newAmount;
    }
