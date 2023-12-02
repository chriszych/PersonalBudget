#ifndef COMMONMETHODS_H
#define COMMONMETHODS_H

#include <sstream>
#include <iostream>

#include <cstdlib>
#include <algorithm>
#include <windows.h>
#include <time.h>

using namespace std;

class CommonMethods {

public:

    static string convertIntToString (int number);
    static int convertStringToInt(string number);
    static double convertStringToDouble(string number);
    static string readLine();
    static char readChar();
    static int readInteger();
    static string removeNotNumbers(string inputString);
    static string convertCommasToDots(string amountToCheck);
    static bool checkIfDateExist(string dateToCheck);
    static bool isDateCorrect(int year, int month, int day);
    static int getCurrentDate();
    static int getCurrentYear();
    static int getCurrentMonth();
    static bool checkIfDataIsDouble(string dataToCheck);
    static int getMonthNumberOfDays(int year, int month);
    static string formatDateForReport(int date);

};
#endif
