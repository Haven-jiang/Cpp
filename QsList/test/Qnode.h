//
// Created by root on 2021/7/30.
//


#pragma once


#include<iostream>
#include<stdlib.h>
#include <cstring>

using namespace std;
struct Qnode {
    int data;
    struct Qnode* next;
};

struct SString {
    char ch[7];
    int length;
};

void Init(SString& s, SString& p) {
    strcpy(p.ch, "abbac");
    strcpy(p.ch, "bac");
}

struct LinkQ {
    Qnode* front;
    Qnode* rear;
};
void InitQ(LinkQ& Q) {

    Qnode* head = (Qnode*)malloc(sizeof(Qnode));
    head->next = nullptr;
    Q.front = Q.rear = head;
    return Q;
}
void InQ(LinkQ& Q,int e) {
    Qnode* p = (Qnode*)malloc(sizeof(Qnode));
    p->next = nullptr;
    p->data = e;
    Q.rear->next = p;
    Q.rear = Q.rear->next;
}
void OutQ(Qnode* front) {
    Qnode* p = (Qnode*)malloc(sizeof(Qnode));
    p = front->next;
    front->next = p->next;
    free(p);
}
void output(LinkQ& Q) {
    if (Q.rear != Q.front) {
        cout << Q.front->next->data << endl;
        Q.front = Q.front->next;
    }
}


