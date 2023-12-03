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
    vector <BudgetItem> incomes, expenses;
    int currentYear, currentMonth, previousMonth, days, prevDays;

    void loadIncomesFromXmlFile();
    void loadExpensesFromXmlFile();
    bool checkIfDateIsInRange(int dateToCheck, int dateStart, int dateFinish);

    int calculateDateStart(string reportType);
    int calculateDateFinish(string reportType);
    string getTimePeriod(string reportType);
    int getCustomDate(string dateType);
    int buildDate(int year, int month, int day);
    int getMonthBefore(int month);
    double displayListOfBudgetItems(string budgetItem, string timePeriod, int dateStart, int dateFinish, vector <BudgetItem> budgetItems);

public:

    BudgetManager(string incomesFileName, string expensesFileName, int idLoggedUser)
        : INCOMES_FILE(incomesFileName), EXPENSES_FILE(expensesFileName), ID_LOGGED_USER(idLoggedUser) {

        currentYear = DateMethods::getCurrentYear();
        currentMonth = DateMethods::getCurrentMonth();
        previousMonth = getMonthBefore(currentMonth);
        days = DateMethods::getMonthNumberOfDays(currentYear, currentMonth);
        prevDays = DateMethods::getMonthNumberOfDays(currentYear, previousMonth);

        loadIncomesFromXmlFile();
        loadExpensesFromXmlFile();
    };

    void addIncome();
    void addExpense();
    void showBalanceSheet(string reportType);

};

#endif
