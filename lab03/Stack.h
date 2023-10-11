//
// Created by balaz on 2023. 10. 11..
//

#ifndef CPP_2022_STACK_H
#define CPP_2022_STACK_H


#include "List.h"

class Stack {
private:
    List list;
public:
    Stack();
    ~Stack();
    void push(int e);
    int pop();
    bool isEmpty() const;
};


#endif //CPP_2022_STACK_H
