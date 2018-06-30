//
// Created by adenaldojr on 29/06/2018.
//
#ifndef EDPA_SIMPLE_QUEUE_H
#define EDPA_SIMPLE_QUEUE_H

#include <iostream>

using namespace std;

template<typename Type>
class simple_queue {
public:
    simple_queue();

    void push(Type node);

    void pop();

    Type front();

    Type back();

    bool empty();

private:

    struct queue_node {
        Type value;
        queue_node *next;
    };

    queue_node *front_of_queue;
    queue_node *back_of_queue;

};


#endif //EDPA_SIMPLE_QUEUE_H
