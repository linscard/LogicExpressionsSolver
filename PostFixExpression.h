#ifndef TP1_POSTFIXEXPRESSION_H
#define TP1_POSTFIXEXPRESSION_H

#include "Stack.h"
#include "Utils.h"

class PostFixExpression {
public:

    PostFixExpression();
    Stack<char>* form(Stack<char> &inFixExp);
private:
    bool operatorIsHigherLastOperator(char item, Stack<char> &operatorStack);
    void solveLastExpression(Stack<char> &operatorStack, Stack<char> &operandStack, Stack<char> &inFixStack,char &item);

};


#endif //TP1_POSTFIXEXPRESSION_H
