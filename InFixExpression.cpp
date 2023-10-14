#include "InFixExpression.h"


Stack<char>* InFixExpression::form(string &p, string &s) {
    char spaceDelimiter = '-';

    auto* tempStak = new Stack<char>();

    int pSize = p.size();
    int sSize = s.size();

    for (int i = 0; i < pSize; i++) {
        char pItem = p[i];
        if(Utils::isInteger(pItem)) {
            char tempArray[4];
            for (int j = 0; j < 4; ++j) {
                tempArray[j] = '0';
            }
            int tempArraySize = 0;
            while (Utils::isInteger(pItem)){
                tempArray[tempArraySize] = pItem;
                i++;
                tempArraySize++;
                pItem = p[i];
            }

            int sCorespondentValuePosition = 0;
            int loopCount = 0;
            for (int j = tempArraySize - 1; j >= 0; --j) {
                int a = Utils::charToInteger(tempArray[j]);
                int b = Utils::power(10,loopCount);

                int tempCount = a*b;
                sCorespondentValuePosition += tempCount;
                loopCount++;
            }

            char sValue = s[sCorespondentValuePosition];
            tempStak->push(sValue);
        }
        if (pItem == '~' || pItem == '&' || pItem == '|'|| pItem == '('|| pItem == ')') {
            tempStak->push(pItem);
        }
    }

    auto* response = new Stack<char>();




    char firstItem, secondItem;
    int countNot;

    while (!tempStak->isEmpty()) {
        countNot = 0;
        firstItem = tempStak->pop();
        if (firstItem == '~' && !tempStak->isEmpty()) {
            countNot += 1;
            secondItem = tempStak->pop();
            if (secondItem == '~') {
                countNot += 1;
                while (secondItem == '~' && !tempStak->isEmpty() ) {
                    secondItem = tempStak->pop();
                    if (secondItem == '~'){
                        countNot += 1;
                    }
                }
            }
            if (secondItem != '~'){
                tempStak->push(secondItem);
            }


        }
        if (countNot == 0 || countNot%2 != 0) {
            response->push(firstItem);
        }
    }
    delete tempStak;
    return response;
}

