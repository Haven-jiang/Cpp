//
// Created by root on 2021/7/28.
//


#pragma once

template<typename ElemType>

class circularQueue {
private:

    template<class ElemTypes>
    
    struct Queue {
         ElemTypes* base;
         int front;
         int rear;
    };

    Queue<ElemType> queue;
    int size;
    bool is_pop = true, is_push = true;

public:
    circularQueue(int size = 20) {
        queue.base = (ElemType*) malloc(size * sizeof(ElemType));
        this->size = size;
        queue.front = 0;
        queue.rear = 0;
    }

    void push(ElemType data) {
        if (!is_push) return;
        queue.base[queue.rear] = data;
        ++queue.rear %= size;
        if (queue.rear == queue.front) is_push = false;
        is_pop = true;
    }

    ElemType pop() {
        if (!is_pop) return -1;
        ElemType data = queue.base[queue.front];
        if (queue.rear == ++queue.front % size) is_pop = false;
        queue.front %= size;
        is_push = true;
        return data;
    }
};


