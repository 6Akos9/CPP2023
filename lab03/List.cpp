//
// Created by balaz on 2023. 10. 11..
//

#include <stdexcept>
#include <iostream>
#include "List.h"
using namespace std;

List::List() {
    first = nullptr;
}

List::~List() {
    while(first != nullptr) {
        Node* tmp = first;
        first = first->next;
        delete tmp;
    }
}

bool List::exists(int d) const {
    for (Node* i = first; i != nullptr; i= i->next) {
        if (i->value == d) {
            return true;
        }
    }
    return false;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    if(first == nullptr){
        return true;
    }
    return false;
}

void List::insertFirst(int d) {
    first = new Node(d, first);
    nodeCounter++;
}

int List::removeFirst() {
    if (first == nullptr) {
        throw std::out_of_range("List is empty");
    }
    int tmp = first->value;
    Node* tmp2 = first;
    first = first->next;
    delete tmp2;
    nodeCounter--;
    return tmp;
}

void List::remove(int d, List::DeleteFlag df) {
    Node* temp = nullptr;
    for (Node* i = first; i != nullptr; i= i->next) {
        if ((i->value == d && df == List::DeleteFlag::EQUAL) ||
        (i->value > d && df == List::DeleteFlag::GREATER) ||
        (i->value < d && df == List::DeleteFlag::LESS)) {
            if(temp == nullptr){
                removeFirst();
                return;
            }
            temp->next = i->next;
            delete i;
            nodeCounter--;
            return;
        }
        temp = i;
    }
}

void List::print() const {
    for (Node* i = first; i != nullptr; i= i->next) {
        cout << i->value << ", ";
    }
    cout << endl;
}

