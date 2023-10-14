#include <iostream>
#include <stdexcept>
#include "Stack.h"
#include "errorTreatment.h"
#include "InFixExpression.h"
#include "PostFixExpression.h"
#include "Tree.h"

int main(int argc, char* argv[]) {
    string programType = argv[1];
    string p = argv[2];
    string s = argv[3];

    checkEntryArgs(p, s);

    cout << "Args:" << endl;
    cout << p << endl;
    cout << s << endl;




    auto* exp = new InFixExpression();
    Stack<char>* infixExp = exp->form(p, s);
    cout << "Expression in infix:" << endl;
    infixExp->printInverse();

    char* array = Utils::copyStackToArray(*infixExp);

    auto* satTree = new Tree<char>;
    satTree->push(array);

//
//    auto* postExp = new PostFixExpression();
//    postExp->form(*infixExp);
//    cout << "Result operand stack: " << endl;
//    postExp->printOperandStack();
//    cout << "Result operator stack: " << endl;
//    postExp->printOperatorStack();
//    postExp->solve();
//    cout << postExp->expressionResult << endl;









    return 0;
}