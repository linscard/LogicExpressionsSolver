#include <iostream>
#include <stdexcept>

using namespace std;

////////////////////////////////////////////////// errorTreatment.h content  //////////////////////////////////////////////////
#ifndef TP1_ERRORTREATMENT_H
#define TP1_ERRORTREATMENT_H
void checkEntryArgs(string p, string s);
#endif //TP1_ERRORTREATMENT_H
////////////////////////////////////////////////// errorTreatment.h content end //////////////////////////////////////////////////

////////////////////////////////////////////////// errorTreatment.cpp content  //////////////////////////////////////////////////
void checkEntryArgs(string p, string s) {
    int pSize = p.size();
    int sSize = s.size();
    if (pSize > 1000000 || sSize > 100) {
        throw new invalid_argument("Args with invalid size.");
    }
}
////////////////////////////////////////////////// errorTreatment.cpp content end //////////////////////////////////////////////////

////////////////////////////////////////////////// Node.h content  //////////////////////////////////////////////////
#ifndef TP1_NODE_H
#define TP1_NODE_H
template <typename T>
class Node
{
public:
    Node();
    Node(const Node& copy);
    ~Node();

    T item;
    Node<T> *next = nullptr;
    Node<T> *previous = nullptr;
};

template<typename T>
Node<T>::Node(const Node &copy) {
    item = copy.item;
    previous = copy.previous;
    next = copy.next;
}

template<typename T>
Node<T>::~Node() {
    next = nullptr;
    previous = nullptr;
}

template <typename T>
Node<T>::Node()
{
    next = nullptr;
    previous = nullptr;
}
#endif // TP1_NODE_H

////////////////////////////////////////////////// Node.h content end //////////////////////////////////////////////////

////////////////////////////////////////////////// Stack.h content  //////////////////////////////////////////////////
#ifndef TP1_PILHA_H
#define TP1_PILHA_H
template <typename T>
class Stack
{
public:
    Stack();
    Stack(const Stack& copy);
    ~Stack();
    void push(T item);
    T pop();
    bool isEmpty();
    void print();
    void printInverse();


    int size = 0;

private:
    Node<T> *first;
    Node<T> *last;
};

// Definitions
template <typename T>
Stack<T>::Stack()
{
    first = new Node<T>();
    first->next = last;
    first->previous = first;
    last = first;
}

template<typename T>
Stack<T>::Stack(const Stack &copy) {
    first = new Node<T>();
    first->next = last;
    first->previous = first;
    last = first;

    auto* current = copy.first;
    int copySize = copy.size;
    for (int i = 0; i < copySize; ++i) {
        push(current->item);
        current = current->next;
    }
}

template<typename T>
Stack<T>::~Stack() {
    while (first != nullptr) {
        Node<T>* temp = first;
        first = first->next;
        delete temp;
    }
}

template<typename T>
void Stack<T>::printInverse() {
    if (isEmpty()) {
        cout << "Stack is Empty!!" << endl;
        return;
    }
    auto *temp = new Node<T>;
    temp = last;
    for (int i = 0; i < size; ++i)
    {
        cout << temp->item << " ";
        temp = temp->previous;
    }
    cout << endl;
    temp = nullptr;
    delete temp;
}

template <typename T>
void Stack<T>::print() {
    if (isEmpty()) {
        cout << "Stack is Empty!!" << endl;
        return;
    }
    auto *temp = new Node<T>;
    temp = first;
    for (int i = 0; i < size; ++i)
    {
        cout << temp->item;
        temp = temp->next;
    }
    cout << endl;
    temp = nullptr;
    delete temp;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        return T();
    }
    T valorlast = last->item;
    Node<T> *temp = last;
    last = last->previous;
    last->next = nullptr;
    size--;
    return valorlast;
}

template <typename T>
void Stack<T>::push(T item)
{

    if (size == 0)
    {
        first->item = item;
        size++;
        return;
    }
    auto *temp = new Node<T>();
    temp->item = item;
    temp->previous = last;
    last->next = temp;
    last = temp;
    size++;
}
#endif // TP1_PILHA_H
////////////////////////////////////////////////// Stack.h content end //////////////////////////////////////////////////


////////////////////////////////////////////////// Utils.h content //////////////////////////////////////////////////
#ifndef TP1_UTILS_H
#define TP1_UTILS_H
class Utils {
public:
    Utils();
    static bool isInteger(char value);
    static int charToInteger(char value);
    static char integerToChar(char value);
    static int power (int base, int exp);
    static char getSATOperator (Stack<char> &stack);
    static void satToBool (Stack<char> &stack, char boolChar);
    static int getSATOperatorPosition(Stack<char> &stack, char sat);
    static void changeStackItem(Stack<char> &stack, char itemToChange, int position);
    static Stack<char>* getStringResponse(Stack<char> &stack);
};
#endif //TP1_UTILS_H
////////////////////////////////////////////////// Utils.h content end //////////////////////////////////////////////////

////////////////////////////////////////////////// Utils.cpp content //////////////////////////////////////////////////
Utils::Utils() = default;

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

void Utils::satToBool(Stack<char> &stack, char boolChar) {
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

int Utils::getSATOperatorPosition(Stack<char> &stack, char sat) {
    auto* temp = new Stack<char>();
    char item;
    int countPosition = 0;
    while (!stack.isEmpty()) {
        item = stack.pop();
        countPosition += 1;
        if (item == sat) {
            temp->push(item);
            break;
        }
        temp->push(item);
    }
    while (!temp->isEmpty()) {
        item = temp->pop();
        stack.push(item);
    }
    return countPosition;
}

void Utils::changeStackItem(Stack<char> &stack, char itemToChange, int position) {
    auto* temp = new Stack<char>();
    int countPosition = 0;
    char item;
    while (!stack.isEmpty()) {
        item = stack.pop();
        countPosition += 1;
        if (countPosition == position) {
            temp->push(itemToChange);
            break;
        }
        temp->push(item);
    }
    while (!temp->isEmpty()) {
        item = temp->pop();
        stack.push(item);
    }
}

Stack<char> *Utils::getStringResponse(Stack<char> &stack) {
    auto* response = new Stack<char>();
    auto* temp = new Stack<char>();
    while (!stack.isEmpty()) {
        char item = stack.pop();
        if (item == '0' || item == '1' || item == 'a') {
            response->push(item);
        }
        temp->push(item);
    }
    while (!temp->isEmpty()) {
        char item = temp->pop();
        stack.push(item);
    }
    return response;
}

////////////////////////////////////////////////// Utils.cpp content end //////////////////////////////////////////////////




////////////////////////////////////////////////// InFixExpression.h content  //////////////////////////////////////////////////
#ifndef TP1_FORMINFIXEXPRESSION_H
#define TP1_FORMINFIXEXPRESSION_H
class InFixExpression {
public:
    InFixExpression() = default;
    Stack<char>* form(string &p, string &s);
};
#endif //TP1_FORMINFIXEXPRESSION_H
////////////////////////////////////////////////// InFixExpression.h content end //////////////////////////////////////////////////

////////////////////////////////////////////////// InFixExpression.cpp content  //////////////////////////////////////////////////
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
            while (secondItem == '~' && !tempStak->isEmpty() ) {
                countNot += 1;
                secondItem = tempStak->pop();
            }
            tempStak->push(secondItem);
        }
        if (countNot == 0 || countNot%2 != 0) {
            response->push(firstItem);
        }
    }
    delete tempStak;
    return response;
}
////////////////////////////////////////////////// InFixExpression.cpp content end //////////////////////////////////////////////////

////////////////////////////////////////////////// PostFixExpression.h content  //////////////////////////////////////////////////
#ifndef TP1_POSTFIXEXPRESSION_H
#define TP1_POSTFIXEXPRESSION_H
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
////////////////////////////////////////////////// PostFixExpression.h content end //////////////////////////////////////////////////

////////////////////////////////////////////////// PostFixExpression.cpp content  //////////////////////////////////////////////////
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
////////////////////////////////////////////////// PostFixExpression.cpp content end //////////////////////////////////////////////////

////////////////////////////////////////////////// TreeNode.h content  //////////////////////////////////////////////////
#ifndef TP1_TREENODE_H
#define TP1_TREENODE_H
class TreeNode {
public:
    TreeNode()  {
        right = nullptr;
        left = nullptr;
    }

    TreeNode(const TreeNode& copy) {
        item = copy.item;
        nodeIsTrue = copy.nodeIsTrue;
        nodeType = copy.nodeType;
        right = copy.right;
        left = copy.left;
    }

    ~TreeNode() {
        delete item;
        right = nullptr;
        left = nullptr;
    }

    Stack<char>* item;
    char nodeIsTrue;
    char nodeType;
    TreeNode *right = nullptr;
    TreeNode *left = nullptr;
};
#endif //TP1_TREENODE_H
////////////////////////////////////////////////// TreeNode.h content end //////////////////////////////////////////////////

////////////////////////////////////////////////// Tree.h content  //////////////////////////////////////////////////
#ifndef TP1_TREE_H
#define TP1_TREE_H
class Tree {
public:
    Tree() {
        root = new TreeNode();
    }

    ~Tree() {
        delete root;
    }

    void grow(Stack<char> &item) {
        auto* possibelItemToRespond = new Stack<char>(item);
        possibleResponse = possibelItemToRespond;
        recursivePush(item, *root);
    }

    Stack<char>* possibleResponse;
    char treeResponse;


private:
    void recursivePush(Stack<char> &item, TreeNode &newRoot) {
        auto* newItem = new Stack<char>(item);

        newRoot.item = newItem;
        newRoot.nodeType = Utils::getSATOperator(item);

        if (newRoot.nodeType == 's'){
            auto* postExp = new PostFixExpression();
            postExp->form(*newRoot.item);
            postExp->solve();
            newRoot.nodeIsTrue = postExp->expressionResult;
            treeResponse = newRoot.nodeIsTrue;
            return;
        } else {
            auto* itemWhitTrue = new Stack<char>(item);
            Utils::satToBool(*itemWhitTrue, '1');

            auto* itemWhitFalse = new Stack<char>(item);
            Utils::satToBool(*itemWhitFalse, '0');

            newRoot.right = new TreeNode();
            recursivePush(*itemWhitTrue, *newRoot.right);

            newRoot.left = new TreeNode();
            recursivePush(*itemWhitFalse, *newRoot.left);
        }

        char rightChildResult = newRoot.right->nodeIsTrue;
        char leftChildResult = newRoot.left->nodeIsTrue;
        int intRightChildResult = Utils::charToInteger(rightChildResult);
        int intLeftChildResult = Utils::charToInteger(leftChildResult);

        if (newRoot.nodeType == 'a') {
            int result = intRightChildResult && intLeftChildResult;
            newRoot.nodeIsTrue = Utils::integerToChar(result);
            treeResponse = newRoot.nodeIsTrue;
        } else if (newRoot.nodeType == 'e') {
            int result = intRightChildResult || intLeftChildResult;
            newRoot.nodeIsTrue = Utils::integerToChar(result);
            treeResponse = newRoot.nodeIsTrue;
            if (result) {
                int ePosition = Utils::getSATOperatorPosition(*newRoot.item, 'e');
                if (intRightChildResult && intLeftChildResult){
                    Utils::changeStackItem(*possibleResponse, 'a', ePosition);
                } else if (intRightChildResult) {
                    Utils::changeStackItem(*possibleResponse, '1', ePosition);
                } else {
                    Utils::changeStackItem(*possibleResponse, '0', ePosition);
                }
            }
        }
    }

    TreeNode *root = nullptr;
};
#endif //TP1_TREE_H
////////////////////////////////////////////////// Tree.h content end //////////////////////////////////////////////////





int main(int argc, char* argv[]) {
    string programType = argv[1];
    string p = argv[2];
    string s = argv[3];

    checkEntryArgs(p, s);

    auto* exp = new InFixExpression();
    Stack<char>* infixExp = exp->form(p, s);

    if (programType == "a") {
        auto* postExp = new PostFixExpression();
        postExp->form(*infixExp);
        postExp->solve();
        cout << postExp->expressionResult << endl;
    } else if (programType == "s") {
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