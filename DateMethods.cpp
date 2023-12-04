#include "DateMethods.h"
#include "ReadAndConvertMethods.h"


bool DateMethods::checkIfDateExist(string dateToCheck) {
    bool testResult = 0;
    int year=0, month=0, day=0;
    string tmpYear="", tmpMonth="", tmpDay="";


    if(dateToCheck.length() == 8) {
        tmpYear = dateToCheck.substr(0,4);
        tmpMonth = dateToCheck.substr(4,2);
        tmpDay = dateToCheck.substr(6,2);

        year = atoi(tmpYear.c_str());
        month = atoi(tmpMonth.c_str());
        day = atoi(tmpDay.c_str());


        if(!isDateCorrect(year, month, day)) {
            testResult = 0;
            cout << "Date is NOT correct, enter once again" << endl;
        } else {
            testResult = 1;
        }

    } else {
        cout << "Date is NOT correct, enter once again" << endl;
        testResult = 0;
    }

    return testResult;
}

bool DateMethods::isDateCorrect(int year, int month, int day) {
    bool testResult = 0;

    int maxDays = getMonthNumberOfDays(year, month);

    time_t myTime;
    struct tm * myDate;

    time(&myTime);
    myDate = localtime(&myTime);

    int currentYear = myDate -> tm_year + 1900;
    int currentMonth = myDate -> tm_mon + 1;

    if(((((year > 1999) && (year < currentYear))
            &&((month >= 1) && (month <= 12)))
            ||((year == currentYear) && (month >= 1) && (month <= currentMonth)))
            &&((day >= 1) && (day <= maxDays))) {
        testResult = 1;
    }

    return testResult;
}

int DateMethods::getCurrentDate() {

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


int DateMethods::getCurrentYear() {

    time_t myTime;
    struct tm * myDate;

    time(&myTime);
    myDate = localtime(&myTime);

    int currentYear = myDate->tm_year + 1900;

    return currentYear;
}

int DateMethods::getCurrentMonth() {

    time_t myTime;
    struct tm * myDate;

    time(&myTime);
    myDate = localtime(&myTime);

    int currentMonth = myDate->tm_mon + 1;

    return currentMonth;
}

int DateMethods::getMonthNumberOfDays(int year, int month) {

    const int DAYS_PER_MONTH[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    int days = DAYS_PER_MONTH[(year % 4 == 0 && year % 100 != 0) || year % 400 == 0][month];

    return days;
}

string DateMethods::formatDateForReport(int date) {
    string dateWithSeparators = "", tmpDate = "";

    tmpDate  = ReadAndConvertMethods::convertIntToString(date);

    dateWithSeparators.append(tmpDate.substr(0,4));
    dateWithSeparators.append("-");
    dateWithSeparators.append(tmpDate.substr(4,2));
    dateWithSeparators.append("-");
    dateWithSeparators.append(tmpDate.substr(6,2));

    return dateWithSeparators;
}
