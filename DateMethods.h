#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <sstream>
#include <iostream>

#include <cstdlib>
#include <algorithm>
#include <windows.h>
#include <time.h>

using namespace std;

class DateMethods {

public:

    static bool checkIfDateExist(string dateToCheck);
    static bool isDateCorrect(int year, int month, int day);
    static int getCurrentDate();
    static int getCurrentYear();
    static int getCurrentMonth();
    static int getMonthNumberOfDays(int year, int month);
    static string formatDateForReport(int date);

};
#endif
