//
// Created by root on 2021/7/26.
//

#ifndef QSLIST_QUEUE_H
#define QSLIST_QUEUE_H

typedef int ElemType_a;

struct queue{
    queue* next;
    ElemType_a data;
};

struct Queue{
    int length;
    queue *front;
    queue *rear;

    static std::string ElemTypetoString(ElemType_a elem);

    static std::string toString(Queue pointer);

    friend std::ostream &operator<<(std::ostream &os, Queue &link) ;
};

Queue* init(Queue* pointer) {
    pointer = (Queue *) malloc(sizeof(Queue));
    if (!pointer) return pointer;
    pointer->front = (queue *) malloc(sizeof(queue));
    if (!pointer->front) return pointer;
    pointer->rear = (queue *) malloc(sizeof(Queue));
    if (!pointer->rear) return pointer;
    pointer->front->next = pointer->rear;
    pointer->rear->next = nullptr;
    pointer->length = 0;
    return pointer;
}

void push(Queue* pointer, ElemType_a data) {
    pointer->rear->data = data;
    pointer->rear->next = (queue *) malloc(sizeof(Queue));
    if (!pointer->rear) return;
    pointer->rear = pointer->rear->next;
    pointer->rear->next = nullptr;
    pointer->length++;
}

ElemType_a pop(Queue* pointer) {
    if (pointer->length == 0) return 0;
    ElemType_a data = pointer->front->next->data;
    queue *GongJuren = pointer->front->next;
    pointer->front->next = GongJuren->next;
    delete GongJuren;
    pointer->length--;
    return data;
}

void delete_all(Queue* pointer) {
    while (pointer->front->next != pointer->rear) {
        queue *GongJuren = pointer->front->next;
        pointer->front->next = GongJuren->next;
        delete GongJuren;
        pointer->length--;
    }
}

std::string Queue::toString(Queue pointer) {
    std::string str = "[";
    queue *GongJuren = pointer.front;
    while (GongJuren->next != pointer.rear) {
        GongJuren = GongJuren->next;
        if (GongJuren != pointer.front->next) str += ", ";
        str += ElemTypetoString(GongJuren->data);
    }str += ']';
    return str;
}

std::string Queue::ElemTypetoString(ElemType_a elem) {
    std::ostringstream out;
    out << elem;
    return out.str();
}

std::ostream &operator<<(std::ostream &os, Queue &link) {
    os << "--------------QUEUE_LINK--------------\n"
    << "data: " << Queue::toString(link) << std::endl
    << "length: " << link.length << std::endl
    << "------------------END------------------\n";
    return os;
}


#endif //QSLIST_QUEUE_H
