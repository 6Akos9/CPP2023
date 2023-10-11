//
// Created by balaz on 2023. 10. 11..
//

#include <iostream>
#include "Stack.h"
using namespace std;

void Stack::push(int e) {
    list.insertFirst(e);
}

int Stack::pop() {
    return list.removeFirst();
}

bool Stack::isEmpty() const {
    return list.empty();
}

Stack::Stack() {
    cout << "Stack created" << endl;
}

Stack::~Stack() {
    cout << "Stack destroyed" << endl;
}

