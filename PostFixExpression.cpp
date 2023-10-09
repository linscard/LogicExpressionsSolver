#include "PostFixExpression.h"

PostFixExpression::PostFixExpression() = default;

Stack<char> *PostFixExpression::form(Stack<char> &inFixStack) {
    char spaceDelimiter = '-';
    char item;

    auto* operatorStack = new Stack<char>();
    auto* operandStack = new Stack<char>();

    int dumbSolution = inFixStack.size;
    for (int i = 0; i < dumbSolution; ++i) {
       item = inFixStack.pop();

        if (Utils::isInteger(item)){
            operandStack->push(item);
        } else if (item != spaceDelimiter){
            if(operatorIsHigherLastOperator(item, *operatorStack)) {
                operatorStack->push(item);
            } else{
                solveLastExpression(*operatorStack, *operandStack, inFixStack, item);
            }
        }
        if (i == (dumbSolution-1) && !operatorStack->isEmpty()) {
            item = operatorStack->pop();
            solveLastExpression(*operatorStack, *operandStack, inFixStack, item);
        }
    }


    return operandStack;
}

bool PostFixExpression::operatorIsHigherLastOperator(char item, Stack<char> &operatorStack) {
    if (operatorStack.isEmpty()){
        return true;
    }
    char lastOperatorStackItem = operatorStack.pop();

    switch (item) {
        case '(':
            operatorStack.push(lastOperatorStackItem);
            return true;
        case '~':
            if (lastOperatorStackItem != '~'){
                operatorStack.push(lastOperatorStackItem);
                return true;
            } else{
                operatorStack.push(lastOperatorStackItem);
                return false;
            }
        case '&':
            if (lastOperatorStackItem != '~' && lastOperatorStackItem != '&'){
                operatorStack.push(lastOperatorStackItem);
                return true;
            } else{
                operatorStack.push(lastOperatorStackItem);
                return false;
            }
        case '|':
            if (lastOperatorStackItem == '(' || lastOperatorStackItem == ')') {
                operatorStack.push(lastOperatorStackItem);
                return true;
            } else {
                operatorStack.push(lastOperatorStackItem);
                return false;
            }
        case ')':
            if (lastOperatorStackItem == '(') {
                operatorStack.push(lastOperatorStackItem);
                return true;
            } else {
                operatorStack.push(lastOperatorStackItem);
                return false;
            }
        default:
            operatorStack.push(lastOperatorStackItem);
            return false;

    }
}

void PostFixExpression::solveLastExpression(Stack<char> &operatorStack, Stack<char> &operandStack, Stack<char> &inFixStack,char &item) {
    char lastOperator, operandOne, operandTwo, charExpressionResult;
    int intOperandOne, intOperandTwo, intExpressionResult;

    bool shouldNotContinue = operatorIsHigherLastOperator(item, operatorStack) && !operatorStack.isEmpty();

    while (!shouldNotContinue){
        if (operatorStack.isEmpty()){
            lastOperator = item;
        } else {
            lastOperator = operatorStack.pop();
        }


        switch (lastOperator) {
            case '(':
                item = inFixStack.pop();
                shouldNotContinue = operatorIsHigherLastOperator(item, operatorStack);
                continue;
            case '~':
                operandOne = operandStack.pop();
                intOperandOne = Utils::charToInteger(operandOne);

                intExpressionResult = !intOperandOne;
                charExpressionResult = Utils::integerToChar(intExpressionResult);

                operandStack.push(charExpressionResult);

                shouldNotContinue = operatorIsHigherLastOperator(item, operatorStack);
                continue;
            case '&':
                operandOne = operandStack.pop();
                operandTwo = operandStack.pop();
                intOperandOne = Utils::charToInteger(operandOne);
                intOperandTwo = Utils::charToInteger(operandTwo);

                intExpressionResult = intOperandOne && intOperandTwo;
                charExpressionResult = Utils::integerToChar(intExpressionResult);

                operandStack.push(charExpressionResult);

                shouldNotContinue = operatorIsHigherLastOperator(item, operatorStack);
                continue;
            case '|':
                operandOne = operandStack.pop();
                operandTwo = operandStack.pop();
                intOperandOne = Utils::charToInteger(operandOne);
                intOperandTwo = Utils::charToInteger(operandTwo);

                intExpressionResult = intOperandOne || intOperandTwo;
                charExpressionResult = Utils::integerToChar(intExpressionResult);

                operandStack.push(charExpressionResult);

                shouldNotContinue = operatorIsHigherLastOperator(item, operatorStack);
                continue;
            default:
                continue;

        }
    }
    if (item != ')') {
        operatorStack.push(item);
    } else {
        operatorStack.pop();
    }


}
