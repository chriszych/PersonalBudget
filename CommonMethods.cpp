#include "CommonMethods.h"

string CommonMethods::convertIntToString (int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string CommonMethods::readLine() {
    string lineInput = "";
    getline(cin, lineInput);
    return lineInput;
}

int CommonMethods::convertStringToInt(string number) {
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}

double CommonMethods::convertStringToDouble(string number) {
    double doubleNumber;
    stringstream iss(number);
    iss >> doubleNumber;

    return doubleNumber;
}

char CommonMethods::readChar() {
    string lineInput = "";
    char lineChar  = {0};

    while (true) {
        getline(cin, lineInput);

        if (lineInput.length() == 1) {
            lineChar = lineInput[0];
            break;
        }
        cout << "Enter single character only :";
    }
    return lineChar;
}

int CommonMethods::readInteger() {
    string inputLine = "";
    int inputNumber = 0;

    while (true) {
        getline(cin, inputLine);

        stringstream myStream(inputLine);
        if (myStream >> inputNumber)
            break;
        cout << "This is not an integer number. Enter again. " << endl;
    }
    return inputNumber;
}

string CommonMethods::removeNotNumbers(string inputString) {
    string outputString ="", tmp = "";


    for(size_t i = 0; i < inputString.length(); ++i) {
        if (isdigit(inputString[i])){
            tmp = inputString[i];
        outputString.append(tmp);
        tmp = "";
    }
    }
    return outputString;
}

string CommonMethods::convertCommasToDots(string amountToCheck) {

    for(size_t i = 0; i < sizeof(amountToCheck); ++i) {
        if (amountToCheck[i] == ',')
            amountToCheck[i] = '.';
    }

    return amountToCheck;
}

bool CommonMethods::checkIfDateExist(string dateToCheck){
    bool testResult = 0;
    int year=0, month=0, day=0;
    string tmpYear="", tmpMonth="", tmpDay="";

    for (size_t i = 0; i < dateToCheck.length(); ++i){
            if(i < 4){
                tmpYear += dateToCheck[i];
            } else if(i > 3 && i < 6){
                tmpMonth += dateToCheck[i];
            } else {
                tmpDay += dateToCheck[i];
            }
    }

    year = atoi(tmpYear.c_str());
    month = atoi(tmpMonth.c_str());
    day = atoi(tmpDay.c_str());

    if(!isDateCorrect(year, month, day)){
        testResult = 0;
        cout << "Date is NOT correct, enter once again" << endl;
    } else {
        testResult = 1;
    }


    return testResult;
}

bool CommonMethods::isDateCorrect(int year, int month, int day){
    bool testResult = 0;

    const int DAYS_PER_MONTH[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};


    time_t myTime;
    struct tm * myDate;

    time(&myTime);
    myDate = localtime(&myTime);

    int currentYear = myDate -> tm_year + 1900;
    int currentMonth = myDate -> tm_mon + 1;

    if(((((year > 1999) && (year < currentYear))
       &&((month >= 1) && (month <= 12)))
       ||((year == currentYear) && (month >= 1) && (month <= currentMonth)))
        &&((day >= 0) && (day <= DAYS_PER_MONTH[(year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))][month]))) {
            testResult = 1;
    }

    return testResult;
}

int CommonMethods::getCurrentDate(){

    time_t myTime;
    struct tm * myDate;

    time(&myTime);
    myDate = localtime(&myTime);

    int currentYear = myDate -> tm_year + 1900;
    int currentMonth = myDate -> tm_mon + 1;
    int currentDay = myDate -> tm_mday;

    int currentDate = currentYear*10000 + currentMonth*100 + currentDay;

return currentDate;
}


int CommonMethods::getCurrentYear(){

    time_t myTime;
    struct tm * myDate;

    time(&myTime);
    myDate = localtime(&myTime);

    int currentYear = myDate->tm_year + 1900;

return currentYear;
}

int CommonMethods::getCurrentMonth(){

    time_t myTime;
    struct tm * myDate;

    time(&myTime);
    myDate = localtime(&myTime);

    int currentMonth = myDate->tm_mon + 1;

    return currentMonth;
}

bool CommonMethods::checkIfDataIsDouble(string dataToCheck) {
    bool testResult = 0;
    try {
        std::stod(dataToCheck);
        testResult = 1;
    } catch (exception &e) {
        testResult = 0;
    }
    return testResult;
}

int CommonMethods::getMonthNumberOfDays(int year, int month){

    const int DAYS_PER_MONTH[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    int days = DAYS_PER_MONTH[(year % 4 == 0 && year % 100 != 0) || year % 400 == 0][month];

    return days;
}

string CommonMethods::formatDateForReport(int date){
    string dateWithSeparators = "", tmpDate = "";

    tmpDate  = convertIntToString(date);
    //test
    //cout << "Test tmp Date: " << tmpDate << " < ";
    for(size_t i = 0; i < tmpDate.size(); ++i){
        dateWithSeparators += tmpDate[i];
        if (( i == 3) || (i == 5)){
            dateWithSeparators += '-';
        }
    }

return dateWithSeparators;
}
