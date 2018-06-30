//
// Created by adenaldojr on 29/06/2018.
//

#include "simple_queue.h"

template<typename Type>
simple_queue<Type>::simple_queue() {
    back_of_queue = NULL;
    front_of_queue = NULL;
}

template<typename Type>
void simple_queue<Type>::push(Type node) {
    queue_node *aux = new queue_node;
    aux->value = node;
    aux->next == NULL;
    if (empty()) {
        front_of_queue = back_of_queue = aux;
    } else {
        back_of_queue->next = aux;
        back_of_queue = aux;
    }

}

template<typename Type>
void simple_queue<Type>::pop() {
    if (empty()) {
        cout << "A fila está vazia. \n";
    } else {
        if(front_of_queue==back_of_queue){
            front_of_queue=back_of_queue=NULL;
        } else{
            queue_node *aux = front_of_queue;
            front_of_queue = front_of_queue->next;
            delete aux;
        }
    }
}

template<typename Type>
Type simple_queue<Type>::front() {
    if (empty())
        cout << "A fila está vazia. \n";
    else
        return front_of_queue->value;
}

template<typename Type>
Type simple_queue<Type>::back() {
    if (empty())
        cout << "A fila está vazia. \n";
    else
        return back_of_queue->value;
}

template<typename Type>
bool simple_queue<Type>::empty() {
    return (front_of_queue == NULL);
}