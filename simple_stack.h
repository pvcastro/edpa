//
// Created by adenaldojr on 28/06/2018.
//
#ifndef EDPA_SIMPLESTACK_H
#define EDPA_SIMPLESTACK_H
#include <iostream>

using namespace std;

template <typename Type>
class simple_stack {

public:
    simple_stack();
    void push(Type node);
    void pop();
    Type top();
    bool empty();

private:

    struct stack_node {
        Type value;
        stack_node *next;
    };

    stack_node *top_of_stack;
};

#endif