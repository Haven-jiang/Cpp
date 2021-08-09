//
// Created by root on 2021/7/26.
//

#pragma once

#include <ostream>

template <class ElemType>
class abstractLink {
protected:
    template <typename ElemTypes>
    struct Link{
        ElemTypes data;
        Link *next;
    };
    Link<ElemType>* temp;
    Link<int>* head;
public:
    void InitLink(int length);
    void insert(int, ElemType);
    void insert(ElemType);
    void LinkDelete(int i);
    std::string toString();
    std::string ElemtoString(ElemType elem);
};

template<class ElemType>
void abstractLink<ElemType>::insert(int i, ElemType insertData) {
    if (i > head->data + 1 || i <= 0) return;
    temp = head;
    for (int j = 0; j < i - 1; ++j) temp = temp->next;
    Link<ElemType> *new_base = (Link<ElemType> *) malloc(sizeof(Link<ElemType>));
    if (!new_base) return;
    new_base->data = insertData;
    new_base->next = temp->next;
    temp->next = new_base;
    new_base = nullptr;
    this->head->data++;
    if (i == head->data + 1) this->temp = temp->next;
}

template<class ElemType>
void abstractLink<ElemType>::insert(ElemType insertData) {
    Link<ElemType> *new_base = (Link<ElemType> *) malloc(sizeof(Link<ElemType>));
    if (!new_base) return;
    new_base->data = insertData;
    temp->next = new_base;
    new_base = nullptr;
}

template<class ElemType>
void abstractLink<ElemType>::LinkDelete(int i) {
    if (i > head->data) return;
    temp = head;
    for (int i = 0; i < head->data; ++i) temp = temp->next;
    Link<ElemType> *del = temp->next;
    temp->next = del->next;
    delete del;
    head->data--;
}

template<class ElemType>
std::string abstractLink<ElemType>::toString() {
    std::string str = "[";
    temp = head;
    for (int i = 0; i < head->data; i++) {
        if (temp != head) str += ", ";
        str += ElemtoString(temp->data);
        temp = temp->next;
    }
    str += ']';
    return str;
}

template<class ElemType>
std::string abstractLink<ElemType>::ElemtoString(ElemType elem) {
    std::ostringstream out;
    out << elem;
    return out.str();
}


