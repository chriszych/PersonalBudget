#include "BudgetManager.h"

void BudgetManager::addIncome() {
    budgetItemFile.addBudgetItemToXmlFile(ID_LOGGED_USER, INCOMES_FILE);
}
void BudgetManager::addExpense() {
    budgetItemFile.addBudgetItemToXmlFile(ID_LOGGED_USER, EXPENSES_FILE);
}
void BudgetManager::loadIncomesFromXmlFile() {
    incomes = budgetItemFile.loadBudgetItemsFromXmlFile(ID_LOGGED_USER, INCOMES_FILE);
}
void BudgetManager::loadExpensesFromXmlFile() {
    expenses = budgetItemFile.loadBudgetItemsFromXmlFile(ID_LOGGED_USER, EXPENSES_FILE);
}

bool BudgetManager::checkIfDateIsInRange(int dateToCheck, int dateStart, int dateFinish) {
    bool testResult = 0;

    if(dateToCheck >= dateStart && dateToCheck <= dateFinish) {
        testResult = 1;
    } else {
        testResult = 0;
    }
    return testResult;
}

void BudgetManager::showBalanceSheet(string reportType) {

    bool incomesTestResult = 0;
    bool expensesTestResult = 0;
    double sumIncomes = 0;
    double sumExpenses = 0;
    int dateStart, dateFinish;
    string dateStartToCheck, dateFinishToCheck;
    string timePeriod = "";

    int currentYear = CommonMethods::getCurrentYear();
    int currentMonth = CommonMethods::getCurrentMonth();
    int previousMonth = currentMonth - 1;
    int days = CommonMethods::getMonthNumberOfDays(currentYear, currentMonth);
    int prevDays = CommonMethods::getMonthNumberOfDays(currentYear, previousMonth);

    if (reportType == "currentMonth") {

        dateStart = currentYear*10000+currentMonth*100+1;
        dateFinish = currentYear*10000+currentMonth*100+days;
        timePeriod = "Current month";


    } else if (reportType == "previousMonth") {

        dateStart = currentYear*10000+previousMonth*100+1;
        dateFinish = currentYear*10000+previousMonth*100+prevDays;
        timePeriod = "Previous month";

    } else if (reportType == "customPeriod") {
        string dateStartToCheck, dateFinishToCheck;

        do {
            cout << "Enter start date for the report: ";
            dateStartToCheck = CommonMethods::removeNotNumbers(CommonMethods::readLine());
            dateStart = atoi(dateStartToCheck.c_str());
        } while(!CommonMethods::checkIfDateExist(dateStartToCheck));

        do {
            cout << "Enter finish date for the report: ";
            dateFinishToCheck = CommonMethods::removeNotNumbers(CommonMethods::readLine());
            dateFinish = atoi(dateFinishToCheck.c_str());
        } while(!CommonMethods::checkIfDateExist(dateFinishToCheck));

        //timePeriod.append(dateStartToCheck);
        //timePeriod.append(" to ");
        //timePeriod.append(dateFinishToCheck);
        timePeriod = "Custom period";

    } else {
        cout << "Wrong reportType parameter" << endl;
    }

    system("cls");
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Balance sheet for: " << timePeriod << ", from " << CommonMethods::formatDateForReport(dateStart) << " to " << CommonMethods::formatDateForReport(dateFinish) <<endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "List of incomes: " << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "| No |   Date   |   Amount   |   Description                           |" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    if(incomes.size() > 0) {
        int listNumber = 0;
        cout << setprecision(2) << fixed << showpoint << right;

        for (vector <BudgetItem>::iterator itr = incomes.begin(); itr != incomes.end(); ++itr) {
            if(checkIfDateIsInRange(itr -> getDate(), dateStart, dateFinish)) {
                incomesTestResult = 1;
                ++listNumber;
                cout << " " << setw(3) << setfill('0') << listNumber << ". " << CommonMethods::formatDateForReport(itr -> getDate()) << " " << setw(12) << setfill(' ') << itr -> getAmount() << " " << itr -> getDescription() << endl;
                sumIncomes += itr -> getAmount();
            }
        }
    }
    if (incomesTestResult == 0) {
        cout << "-- No incomes for " << timePeriod << " --" << endl;
    }

    cout << "------------------------------------------------------------------------" << endl;
    cout << "List of expenses: " << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "| No |   Date   |   Amount   |   Description                           |" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    if(expenses.size() > 0) {
        int listNumber = 0;

        for (vector <BudgetItem>::iterator itr = expenses.begin(); itr != expenses.end(); ++itr) {
            if(checkIfDateIsInRange(itr -> getDate(), dateStart, dateFinish)) {
                expensesTestResult = 1;
                ++listNumber;
                cout << " " << setw(3) << setfill('0') << listNumber << ". " << CommonMethods::formatDateForReport(itr -> getDate()) << " " << setw(12) << setfill(' ') << itr -> getAmount() << " " << itr -> getDescription() << endl;
                sumExpenses += itr -> getAmount();
            }
        }
    }
    if (expensesTestResult == 0) {
        cout << "-- No expenses for " << timePeriod << " --" << endl;
    }

    cout << "------------------------------------------------------------------------" << endl;
    cout << "       Summary: " << timePeriod << ", from " << CommonMethods::formatDateForReport(dateStart) << " to " << CommonMethods::formatDateForReport(dateFinish) <<endl;
    cout << "       Incomes: " << setw(12) << sumIncomes << endl;
    cout << "      Expenses: " << setw(12) << sumExpenses << endl;
    cout << "       Balance: " << setw(12) << sumIncomes - sumExpenses << endl;
    cout << "------------------------------------------------------------------------" << endl;
    system("pause");

}
