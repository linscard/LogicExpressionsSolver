#include "Utils.h"

Utils::Utils() {
}

bool Utils::isInteger(char value) {
    return (value >= '0' && value <= '9');
}

int Utils::charToInteger(char value) {

    switch (value) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return -1;
    }
}

int Utils::power(int base, int exp) {
    int response = 1;

    for (int i = 0; i < exp; ++i) {
        response *= base;
    }

    return response;
}

char Utils::integerToChar(char value) {
    switch (value) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            return '~';
    }
}

char Utils::getSATOperator(Stack<char> &stack) {
    auto* temp = new Stack<char>();
    char item;
    char SATitem = 's';
    while (!stack.isEmpty()) {
        item = stack.pop();
        if (item == 'a' || item == 'e') {
            SATitem = item;
            temp->push(item);
            break;
        }
        temp->push(item);
    }
    while (!temp->isEmpty()) {
        item = temp->pop();
        stack.push(item);
    }
    return SATitem;
}

Stack<char>*  Utils::satToBool(Stack<char> &stack, char boolChar) {
    auto* temp = new Stack<char>();
    char item;

    while (!stack.isEmpty()) {
        item = stack.pop();
        if (item == 'a' || item == 'e') {
            temp->push(boolChar);
            break;
        }
        temp->push(item);
    }
    while (!temp->isEmpty()) {
        item = temp->pop();
        stack.push(item);
    }
}

char* Utils::copyStackToArray(Stack<char> &stack) {
    int stackSize = stack.size;
    auto* temp = new Stack<char>();
    char* response = new char[stackSize];

    for (int i = 0; i < stackSize; ++i) {
        char item = stack.pop();
        response[i] = item;
        temp->push(item);
    }

    while (!temp->isEmpty()) {
        char item = temp->pop();
        stack.push(item);
    }

    return response;
}
