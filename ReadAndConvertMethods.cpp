#include "ReadAndConvertMethods.h"

string ReadAndConvertMethods::convertIntToString (int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string ReadAndConvertMethods::readLine() {
    string lineInput = "";
    getline(cin, lineInput);
    return lineInput;
}

char ReadAndConvertMethods::readChar() {
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

string ReadAndConvertMethods::removeNotNumbers(string inputString) {
    string outputString ="", tmp = "";

    for(size_t i = 0; i < inputString.length(); ++i) {
        if (isdigit(inputString[i])) {
            tmp = inputString[i];
            outputString.append(tmp);
            tmp = "";
        }
    }
    return outputString;
}

string ReadAndConvertMethods::convertCommasToDots(string amountToCheck) {

    for(size_t i = 0; i < sizeof(amountToCheck); ++i) {
        if (amountToCheck[i] == ',')
            amountToCheck[i] = '.';
    }

    return amountToCheck;
}


bool ReadAndConvertMethods::checkIfDataIsDouble(string dataToCheck) {
    bool testResult = 0;
    try {
        stod(dataToCheck);
        testResult = 1;
    } catch (exception &e) {
        testResult = 0;
    }
    return testResult;
}
