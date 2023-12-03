#include "BudgetManager.h"

void BudgetManager::addIncome() {
    budgetItemFile.addBudgetItemToXmlFile(ID_LOGGED_USER, INCOMES_FILE);
    loadIncomesFromXmlFile();
}
void BudgetManager::addExpense() {
    budgetItemFile.addBudgetItemToXmlFile(ID_LOGGED_USER, EXPENSES_FILE);
    loadExpensesFromXmlFile();
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

    double sumIncomes = 0;
    double sumExpenses = 0;
    int dateStart, dateFinish;
    string timePeriod = "";

    dateStart = calculateDateStart(reportType);
    dateFinish = calculateDateFinish(reportType);
    timePeriod = getTimePeriod(reportType);


    system("cls");
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Balance sheet for: " << timePeriod << ", from " << DateMethods::formatDateForReport(dateStart) << " to " << DateMethods::formatDateForReport(dateFinish) <<endl;

    sumIncomes = displayListOfBudgetItems("incomes", timePeriod, dateStart, dateFinish, incomes);
    sumExpenses = displayListOfBudgetItems("expenses", timePeriod, dateStart, dateFinish, expenses);

    cout << "------------------------------------------------------------------------" << endl;
    cout << "       Summary: " << timePeriod << ", from " << DateMethods::formatDateForReport(dateStart) << " to " << DateMethods::formatDateForReport(dateFinish) <<endl;
    cout << "       Incomes: " << setw(12) << sumIncomes << endl;
    cout << "      Expenses: " << setw(12) << sumExpenses << endl;
    cout << "       Balance: " << setw(12) << sumIncomes - sumExpenses << endl;
    cout << "------------------------------------------------------------------------" << endl;
    system("pause");

}

int BudgetManager::calculateDateStart(string reportType) {

    int dateStart = 0;
    string dateStartToCheck = "";

    if (reportType == "currentMonth") {
        dateStart = buildDate(currentYear, currentMonth, 1);

    } else if (reportType == "previousMonth") {
        dateStart = buildDate(currentYear, previousMonth, 1);

    } else if (reportType == "customPeriod") {
        cout << "Allowed date range from 2000-01-01 to " << DateMethods::formatDateForReport(buildDate(currentYear, currentMonth, days)) << " in YYYYMMDD format. " << endl;
        dateStart = getCustomDate("start");

    } else {
        cout << "Wrong reportType parameter" << endl;
    }
    return dateStart;
}

int BudgetManager::calculateDateFinish(string reportType) {

    int dateFinish = 0;
    string dateFinishToCheck = "";

    if (reportType == "currentMonth") {
        dateFinish = buildDate(currentYear, currentMonth, days);

    } else if (reportType == "previousMonth") {
        dateFinish = buildDate(currentYear, previousMonth, prevDays);

    } else if (reportType == "customPeriod") {
        dateFinish = getCustomDate("finish");

    } else {
        cout << "Wrong reportType parameter" << endl;
    }
    return dateFinish;
}

string BudgetManager::getTimePeriod(string reportType) {
    string timePeriod = "";

    if (reportType == "currentMonth") {
        timePeriod = "Current month";

    } else if (reportType == "previousMonth") {
        timePeriod = "Previous month";

    } else if (reportType == "customPeriod") {
        timePeriod = "Custom period";

    } else {
        cout << "Wrong reportType parameter" << endl;
    }

    return timePeriod;
}

int BudgetManager::getCustomDate(string dateType) {

    string dateToCheck = "";
    int customDate = 0;

    do {
        cout << "Preparing custom report/";
        cout << "Enter " << dateType << " date for the report (YYYYMMDD): ";
        dateToCheck = ReadAndConvertMethods::removeNotNumbers(ReadAndConvertMethods::readLine());
        customDate = atoi(dateToCheck.c_str());
    } while(!DateMethods::checkIfDateExist(dateToCheck));

    return customDate;
}

int BudgetManager::buildDate(int year, int month, int day) {
    return year * 10000 + month * 100 + day;
}

int BudgetManager::getMonthBefore(int month) {
    int previousMonth = 0;

    if (month != 1) {
        previousMonth = month - 1;
    } else {
        previousMonth = 12;
    }
    return previousMonth;
}

double BudgetManager::displayListOfBudgetItems(string budgetItem, string timePeriod, int dateStart, int dateFinish, vector <BudgetItem> budgetItems) {

    double sumOfBudgetItems = 0;
    bool budgetItemTestResult = 0;

    cout << "------------------------------------------------------------------------" << endl;
    cout << "                   List of " << budgetItem << ":                        " << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "| No |   Date   |   Amount   |   Description                           |" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    if(budgetItems.size() > 0) {
        int listNumber = 0;
        cout << setprecision(2) << fixed << showpoint << right;

        for (vector <BudgetItem>::iterator itr = budgetItems.begin(); itr != budgetItems.end(); ++itr) {
            if(checkIfDateIsInRange(itr -> getDate(), dateStart, dateFinish)) {
                budgetItemTestResult = 1;
                ++listNumber;
                cout << " " << setw(3) << setfill('0') << listNumber << ". " << DateMethods::formatDateForReport(itr -> getDate()) << " " << setw(12) << setfill(' ') << itr -> getAmount() << " " << itr -> getDescription() << endl;
                sumOfBudgetItems += itr -> getAmount();
            }
        }
    }
    if (budgetItemTestResult == 0) {
        cout << "-- No " << budgetItem << " for " << timePeriod << " --" << endl;
    }
    return sumOfBudgetItems;
}
