#ifndef TP1_POSTFIXEXPRESSION_H
#define TP1_POSTFIXEXPRESSION_H

#include "Utils.h"

class PostFixExpression {
public:

    PostFixExpression();
    void form(Stack<char> &inFixExp);
    void solve();
    void printOperatorStack();
    void printOperandStack();
    char expressionResult;


private:
    void invertOperandStack();

    bool shouldReorganize(char item, Stack<char> &operatorStack);

    Stack<char>* operatorStack = new Stack<char>();
    Stack<char>* operandStack = new Stack<char>();

};


#endif //TP1_POSTFIXEXPRESSION_H
