#include <iostream>
#include "List.h"
#include "Stack.h"

int main() {
    /*List list;
    list.insertFirst(17);
    list.insertFirst(6);
    list.insertFirst(2);
    list.print();
    list.insertFirst(7);
    list.print();
    list.remove(7, List::DeleteFlag::EQUAL);
    list.print();*/

    Stack stack;
    stack.push(3);
    stack.push(2);
    stack.push(1);
    stack.pop();
    return 0;
}
