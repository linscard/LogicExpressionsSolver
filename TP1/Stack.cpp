//#include "Stack.h"
//
//Stack::Stack() {
//    first = new Node<string>();
//    first->next = last;
//    first->previous = first;
//    last = first;
//}
//
//void Stack::push(string item) {
//
//
//    if (size == 0){
//      first->item = item;
//      size ++;
//      return;
//    }
//    Node<string>* temp = new Node<string>();
//    temp->item = item;
//    temp->previous = last;
//    last->next = temp;
//    last = temp;
//    size ++;
//}
//
//bool Stack::isEmpty() {
//    return size == 0;
//}
//
//string Stack::pop() {
//    if (isEmpty() ) {
//        return "Lista isEmpty";
//    }
//    string valorlast = last->item;
//    Node<string>* temp = last;
//    last = last->previous;
//    last->next = nullptr;
////    if (size == 1 ) {
////        last->item = "";
////    } else {
////        delete temp;
////    }
//    size --;
//    return valorlast;
//}
