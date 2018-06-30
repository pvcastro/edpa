//
// Created by adenaldojr on 28/06/2018.
//
#include "simple_stack.h"

template<typename Type>
simple_stack<Type>::simple_stack() {
    top_of_stack = NULL;
}

template<typename Type>
void simple_stack<Type>::push(Type node) {
    stack_node *aux = new stack_node;
    aux->value = node;
    aux->next = top_of_stack;
    top_of_stack = aux;
}

template<typename Type>
void simple_stack<Type>::pop() {
    stack_node *aux = top_of_stack;
    top_of_stack = top_of_stack->next;
    delete aux;
}

template<typename Type>
Type simple_stack<Type>::top() {
    if (empty())
        cout << "A pilha está vazia. \n";
    else
        return top_of_stack->value;
}

template<typename Type>
bool simple_stack<Type>::empty() {
    return (top_of_stack == NULL);
}