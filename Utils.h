#include "Stack.h"
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
    static char getSATOperator (Stack<char> &stack);
    static void satToBool (Stack<char> &stack, char boolChar);
    static char* copyStackToArray(Stack<char> &stack);
    static void invertStack(Stack<char> &stack);
};


#endif //TP1_UTILS_H
