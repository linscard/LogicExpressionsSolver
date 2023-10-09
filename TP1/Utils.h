#include <iostream>
using namespace std;

#ifndef TP1_UTILS_H
#define TP1_UTILS_H

class Utils {
public:
    Utils();
    static bool isInteger(char value);
    static int charToInteger(char value);
    static char integerToChar(char value);
    static int power (int base, int exp);
};


#endif //TP1_UTILS_H
