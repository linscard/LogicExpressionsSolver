#include <iostream>
#include <stdexcept>
#include "Stack.h"
#include "errorTreatment.h"
#include "InFixExpression.h"
#include "PostFixExpression.h"


int main(int argc, char* argv[]) {
    string p = argv[1];
    string s = argv[2];

    checkEntryArgs(p, s);

    int pSize = p.size();
    int sSize = s.size();
    cout << "Args:" << endl;
    cout << p << endl;
    cout << s << endl;

    auto* exp = new InFixExpression();
    Stack<char>* infixExp = exp->form(p, s);
    cout << "Expression in infix:" << endl;
    infixExp->printInverse();

    auto* postExp = new PostFixExpression();
    postExp->form(*infixExp);
    cout << "Result operand stack: " << endl;
    postExp->printOperandStack();
    cout << "Result operator stack: " << endl;
    postExp->printOperatorStack();
    postExp->solve();
    cout << "Result: " << postExp->expressionResult << endl;


    cout << "THE END!";







    return 0;
}