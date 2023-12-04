#ifndef READANDCONVERTMETHODS_H
#define READANDCONVERTMETHODS_H

#include <sstream>
#include <iostream>

#include <cstdlib>
#include <algorithm>
#include <windows.h>

using namespace std;

class ReadAndConvertMethods {

public:

    static string convertIntToString (int number);
    static string readLine();
    static char readChar();
    static string removeNotNumbers(string inputString);
    static string convertCommasToDots(string amountToCheck);
    static bool checkIfDataIsDouble(string dataToCheck);

};
#endif
