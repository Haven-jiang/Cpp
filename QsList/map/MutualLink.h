//
// Created by root on 2021/7/26.
//
#pragma once

#include <ostream>
#include "abstractLink.h"

template <typename ElemType>

class MutualLink : public abstractLink<ElemType> {

private:
    template <typename ElemTypes>
    struct Link : public abstractLink<ElemType>::template Link<ElemTypes>{
        Link *next;
        Link *prev;
        ElemTypes data;
    };

    Link<int> *head;
    Link<int> *rear;
    Link<ElemType> *temp;

public:
    MutualLink(int length = 0) {
        Link<int> *new_head = (Link<int> *) malloc(sizeof(Link<int>));
        if (!new_head) return;
        Link<int> *new_rear = (Link<int> *) malloc(sizeof(Link<int>));
        if (!new_rear) return;
        new_head->data = 0;
        new_rear->data = 0;
        head = new_head;
        head->next = new_rear;
        rear = new_rear;
        rear->prev = head;
        for (int i = 0; i < length; ++i) insert(0);
    }

    void insert(ElemType data) {
        temp = rear;
        Link<ElemType> *new_base = (Link<ElemType> *) malloc(sizeof(Link<ElemType>));
        if (!new_base) return;
        new_base->data = data;
        temp->prev->next = new_base;
        new_base->prev = temp->prev;
        new_base->next = temp;
        temp->prev = new_base;
        new_base = nullptr;
        head->data++;
    }

    void insert(int index, ElemType data) {
        if (index > head->data + 1 || index < 1) return;
        if (index == head->data + 1) insert(data);
        temp = head;
        for (int i = 0; i < index; ++i) temp = temp->next;
        Link<ElemType> *new_base = (Link<ElemType> *) malloc(sizeof(Link<ElemType>));
        if (!new_base) return;
        new_base->data = data;
        temp->prev->next = new_base;
        new_base->prev = temp->prev;
        new_base->next = temp;
        temp->prev = new_base;
        new_base = nullptr;
        head->data++;
    }

    friend std::ostream &operator<<(std::ostream &os, MutualLink &link) {
        os << "data: " << link.toString() + '\n'
           << "length: " << link.head->data << std::endl
           << "temp: " << link.temp;
        return os;
    }

    std::string toString() {
        std::string str = "[";
        temp = head->next;
        for (int i = 0; i < head->data; i++) {
            if (temp != head->next) str += ", ";
            str += ElemtoString(temp->data);
            temp = temp->next;
        }
        str += ']';
        return str;
    }

    std::string ElemtoString(ElemType elem) {
        std::ostringstream out;
        out << elem;
        return out.str();
    }
};