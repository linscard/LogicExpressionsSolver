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
