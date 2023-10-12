#include "PostFixExpression.h"

PostFixExpression::PostFixExpression() = default;

void PostFixExpression::form(Stack<char> &inFixStack) {
    char spaceDelimiter = '-';
    char item;

    int dumbSolution = inFixStack.size;
    for (int i = 0; i < dumbSolution; ++i) {
       item = inFixStack.pop();

        if (Utils::isInteger(item)){
            operandStack->push(item);
        } else if(!shouldReorganize(item, *operatorStack)) {
            operatorStack->push(item);
        } else{
            while (shouldReorganize(item, *operatorStack)) {
                char lastOperator = operatorStack->pop();
                if (lastOperator != '(' && lastOperator != ')' ){
                    operandStack->push(lastOperator);
                }
            }
            if (item != '(' && item != ')' ){
                operatorStack->push(item);
            }
        }
    }
    while (!operatorStack->isEmpty()) {
        char lastOperator = operatorStack->pop();
        if (lastOperator != '(' && lastOperator != ')' ) {
            operandStack->push(lastOperator);
        }
    }
}

bool PostFixExpression::shouldReorganize(char item, Stack<char> &operatorStack) {
    if (operatorStack.isEmpty()){
        return false;
    }
    char lastOperatorStackItem = operatorStack.pop();

    switch (item) {
        case '(':
            operatorStack.push(lastOperatorStackItem);
            return false;
        case '~':
            if (lastOperatorStackItem == '(' || lastOperatorStackItem == ')'){
                operatorStack.push(lastOperatorStackItem);
                return false;
            } else{
                operatorStack.push(lastOperatorStackItem);
                return true;
            }
        case '&':
            if (lastOperatorStackItem == '(' || lastOperatorStackItem == ')' || lastOperatorStackItem == '|'){
                operatorStack.push(lastOperatorStackItem);
                return false;
            } else{
                operatorStack.push(lastOperatorStackItem);
                return true;
            }
        case '|':
            if (lastOperatorStackItem == '(' || lastOperatorStackItem == ')') {
                operatorStack.push(lastOperatorStackItem);
                return false;
            } else {
                operatorStack.push(lastOperatorStackItem);
                return true;
            }
        case ')':
            if (lastOperatorStackItem == '(') {
                return false;
            } else {
                operatorStack.push(lastOperatorStackItem);
                return true;
            }
        default:
            operatorStack.push(lastOperatorStackItem);
            return false;

    }
}

void PostFixExpression::solve() {
    invertOperandStack();
    auto* tempOperand = new Stack<char>();
    int stackSize = operandStack->size;
    for (int i = 0; i < stackSize; ++i) {
        char item = operandStack->pop();
        if (Utils::isInteger(item)){
            tempOperand->push(item);
        } else {
            char operandOne, operandTwo, charExpressionResult;
            int intOperandOne, intOperandTwo, intExpressionResult;

            switch (item) {
                case '~':
                    operandOne = tempOperand->pop();
                    intOperandOne = Utils::charToInteger(operandOne);

                    intExpressionResult = !intOperandOne;
                    charExpressionResult = Utils::integerToChar(intExpressionResult);

                    tempOperand->push(charExpressionResult);
                    continue;

                case '&':
                    operandOne = tempOperand->pop();
                    operandTwo = tempOperand->pop();
                    intOperandOne = Utils::charToInteger(operandOne);
                    intOperandTwo = Utils::charToInteger(operandTwo);

                    intExpressionResult = intOperandOne && intOperandTwo;
                    charExpressionResult = Utils::integerToChar(intExpressionResult);

                    tempOperand->push(charExpressionResult);
                    continue;

                case '|':
                    operandOne = tempOperand->pop();
                    operandTwo = tempOperand->pop();
                    intOperandOne = Utils::charToInteger(operandOne);
                    intOperandTwo = Utils::charToInteger(operandTwo);

                    intExpressionResult = intOperandOne || intOperandTwo;
                    charExpressionResult = Utils::integerToChar(intExpressionResult);

                    tempOperand->push(charExpressionResult);
                    continue;
                default:
                    continue;

            }
        }
    }
    expressionResult = tempOperand->pop();
}

void PostFixExpression::invertOperandStack() {
    auto* temp = new Stack<char>();
    while(!operandStack->isEmpty()) {
        char item = operandStack->pop();
        temp->push(item);
    }
    auto* toDelete = new Stack<char>();
    toDelete = operandStack;
    operandStack = temp;
    delete toDelete;
}

void PostFixExpression::printOperandStack() {
    operandStack->print();
}

void PostFixExpression::printOperatorStack() {
    operatorStack->print();
}


