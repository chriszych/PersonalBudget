#include "BudgetItem.h"
#include "BudgetItemFile.h"
#include "Markup.h"

int BudgetItemFile::getLastIncomeId(){
    return lastIncomeId;
}

int BudgetItemFile::getLastExpenseId(){
    return lastExpenseId;
}

void BudgetItemFile::setLastIncomeId(int newLastIncomeId){
    lastIncomeId = newLastIncomeId;
}

void BudgetItemFile::setLastExpenseId(int newLastExpenseId){
    lastExpenseId = newLastExpenseId;
}

void BudgetItemFile::addBudgetItemToXmlFile(int idLoggedUser, string xmlFile) {

    CMarkup xml;

    bool fileExists = xml.Load(xmlFile);
    int id, userId;
    string description, date, amount;
    string mainXmlItem = "", addXmlItem = "";
    char dateSelection;

    setLastIncomeId(getLastIdfromXmlFile(xmlFile));

    if (xmlFile == "incomes.xml"){
            mainXmlItem = "Incomes";
            addXmlItem = "Income";

    } else if (xmlFile == "expenses.xml") {
            mainXmlItem = "Expenses";
            addXmlItem = "Expense";

    } else {
        cout << "Not defined XML file!" << endl;
    }


    id = getLastIncomeId() + 1;

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(mainXmlItem);
    }
    do{
    cout << "Adding new " << addXmlItem << "/";
    cout << "Add " << addXmlItem << " with current date: " << DateMethods::formatDateForReport(DateMethods::getCurrentDate()) << " (y/n): ";
        dateSelection = ReadAndConvertMethods::readChar();
    } while(dateSelection != 'Y' && dateSelection != 'y' && dateSelection != 'N' && dateSelection != 'n');

    if (dateSelection == 'Y' || dateSelection == 'y') {

            date = ReadAndConvertMethods::convertIntToString(DateMethods::getCurrentDate());

    } else {

    do{
    cout << "Adding new " << addXmlItem << "/";
    cout << "Enter valid date (YYYYMMDD): ";
    date = ReadAndConvertMethods::removeNotNumbers(ReadAndConvertMethods::readLine());
    }while (!DateMethods::checkIfDateExist(date));
    }

        do {
        cout << "Adding new " << addXmlItem << "/";
        cout << "Enter amount: ";
        amount = ReadAndConvertMethods::convertCommasToDots(ReadAndConvertMethods::readLine());
        } while (!ReadAndConvertMethods::checkIfDataIsDouble(amount));

        cout << "Adding new " << addXmlItem << "/";
        cout << "Enter description: ";
        description = ReadAndConvertMethods::readLine();

        userId = idLoggedUser;

        xml.ResetPos();
        xml.FindElem();

        xml.IntoElem();
        xml.AddElem(addXmlItem);
        xml.IntoElem();

        xml.AddElem("id", id);
        xml.AddElem("userId", userId);
        xml.AddElem("date", date);
        xml.AddElem("amount", amount);
        xml.AddElem("description", description);

        xml.Save(xmlFile);
}

int BudgetItemFile::getLastIdfromXmlFile(string xmlFile) {

    CMarkup xml;
    string addXmlItem = "";
    xml.Load(xmlFile);

        if (xmlFile == "incomes.xml"){
            addXmlItem = "Income";

    } else if (xmlFile == "expenses.xml") {
            addXmlItem = "Expense";

    } else {
        cout << "Not defined XML file!" << endl;
    }

    int maxIncomeId = 0;

    xml.ResetPos();
    xml.FindElem(); // Find INCOMES element
    xml.IntoElem(); // inside INCOMES

    while ( xml.FindElem(addXmlItem) ) {

        xml.IntoElem();
        xml.FindElem( "id" );
        int incomeId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.ResetMainPos();

        if(incomeId > maxIncomeId) {
            maxIncomeId = incomeId;
        }

        xml.OutOfElem();
    }

    return maxIncomeId;
}

vector <BudgetItem> BudgetItemFile::loadBudgetItemsFromXmlFile(int ID_LOGGED_USER, string xmlFile){

    CMarkup xml;
    xml.Load(xmlFile);

    vector <BudgetItem> budgetItems;

    BudgetItem tmp;

    string mainXmlItem = "", addXmlItem = "";

    if (xmlFile == "incomes.xml"){
            mainXmlItem = "Incomes";
            addXmlItem = "Income";

    } else if (xmlFile == "expenses.xml") {
            mainXmlItem = "Expenses";
            addXmlItem = "Expense";

    } else {
        cout << "Not defined XML file!" << endl;
    }

    xml.ResetPos();
    xml.FindElem(); // Find MAIN element
    xml.IntoElem(); // inside MAIN

    while ( xml.FindElem(addXmlItem) ) {

        xml.IntoElem();
        xml.FindElem( "id" );
        int currentId = atoi(MCD_2PCSZ(xml.GetData()));

        xml.FindElem( "userId" );
        int currentUserId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.ResetMainPos();


        if(currentUserId == ID_LOGGED_USER){

        tmp.setId(currentId);
        xml.ResetMainPos();

        tmp.setUserId(currentUserId);
        xml.ResetMainPos();

        xml.FindElem("date");
        tmp.setDate(atoi(MCD_2PCSZ(xml.GetData())));
        xml.ResetMainPos();

        xml.FindElem("amount");
        tmp.setAmount(atof(MCD_2PCSZ(xml.GetData())));
        xml.ResetMainPos();

        xml.FindElem("description");
        tmp.setDescription(xml.GetData());
        xml.ResetMainPos();
        budgetItems.push_back(tmp);
        xml.OutOfElem();
        } else {
        xml.OutOfElem();
        }

         sort( budgetItems.begin(), budgetItems.end(), [](BudgetItem &a, BudgetItem &b){ return (a.getDate() < b.getDate());});

    }
    return budgetItems;
}
