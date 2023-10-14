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

    auto* exp = new InFixExpression();
    Stack<char>* infixExp = exp->form(p, s);

    if (programType == "-a") {
        auto* postExp = new PostFixExpression();
        postExp->form(*infixExp);
        postExp->solve();
        cout << postExp->expressionResult << endl;
    } else if (programType == "-s") {
        auto* satTree = new Tree;
        satTree->grow(*infixExp);
        cout << satTree->treeResponse << ' ';
        if (satTree->treeResponse == '1'){
            Stack<char>* response = Utils::getStringResponse(*satTree->possibleResponse);
            response->print();
        }
    }
    return 0;
}