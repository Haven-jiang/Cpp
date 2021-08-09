//
// Created by root on 2021/7/23.
//

#ifndef Q_LIST_LIST_H
#define Q_LIST_LIST_H

#include <cstdlib>
#include <ostream>
#include "abstractLink.h"

template<class ElemType>
class unidirectLink : public abstractLink<ElemType> {

private:
    template<typename ElemTypes>
    struct Link : public abstractLink<ElemType>::template Link<ElemTypes> {
        ElemTypes data;
        Link *next;
    };

    Link<ElemType> *temp;
    Link<int> *head;
    Link<ElemType> *end;
    bool isINIT = true;

    static void TriQuality(Link<ElemType> *delete_data) {
        delete delete_data;
        delete_data = nullptr;
    }

    Link<ElemType> *getPointer(int node = -1) {
        if (node == -1) node = head->data;
        Link<ElemType> *pointer = head;
        for (int i = 0; i < node; ++i) pointer = pointer->next;
        return pointer;
    }

    void update(bool isHead = false) {
        if (isHead) this->head->data++;
        else {
            this->head->data++;
            this->end = end->next;
        }
    }

    void InitLink() {
        if (!isINIT) return;
        Link<ElemType> *new_base = (Link<ElemType> *) malloc(sizeof(Link<ElemType>));
        this->head = new_base;
        this->temp = head;
        this->end = temp;
        head->data = 0;
        isINIT = false;
    }

    void InitLink(int length, bool isHead = false) {
        if (!isINIT) return;
        InitLink();
        head->data = 0;
        if (!isHead) {// 以下纯属练习头插和尾插法, 在本链表中返回值无任何实际意义
            for (int i = 0; i < length; i++) {
                Link<ElemType> *newBase = (Link<ElemType> *) malloc(sizeof(Link<ElemType>));
                newBase->data = i;//rand() % 100 + 1;
                end->next = newBase;
                newBase = nullptr;
                update(isHead);
                // C语言中没有对象概念
                // end充当尾节点, 故称尾插法
            }
        } else {
            for (int i = 0; i < length; i++) {
                //头插法: 看一遍就懂
                Link<ElemType> *newBase = (Link<ElemType> *) malloc(sizeof(Link<ElemType>));
                newBase->data = i + 1;//rand() % 100 + 1;
                newBase->next = head->next;
                head->next = newBase;
                newBase = nullptr;
                if (!i) end = end->next;
                update(isHead);
            }
        }
    }

public:
    virtual ~unidirectLink() {
        this->LinkClear();
    }

    void insert(int i, ElemType insertData) {
        if (i > head->data + 1 || i <= 0) return;
        temp = getPointer(i - 1);
        Link<ElemType> *new_base = (Link<ElemType> *) malloc(sizeof(Link<ElemType>));
        if (!new_base) return;
        new_base->data = insertData;
        new_base->next = temp->next;
        temp->next = new_base;
        new_base = nullptr;
        update(i != head->data + 1);
    }

    void insert(ElemType insertData) {
            Link<ElemType> *new_base = (Link<ElemType> *) malloc(sizeof(Link<ElemType>));
            if (!new_base) return;
            new_base->data = insertData;
            end->next = new_base;
            new_base = nullptr;
            update(false);
    }
    void insert(ElemType insertData, bool isHead) {
        Link<ElemType> *new_base = (Link<ElemType> *) malloc(sizeof(Link<ElemType>));
        if (!new_base) return;
        new_base->data = insertData;
        new_base->next = head->next;
        head->next = new_base;
        new_base = nullptr;
        update(true);
    }

    void LinkDelete(int i) {
        if (i > head->data) return;
        temp = getPointer(i - 1);
        if (i == head->data) end = temp;
        Link<ElemType> *del = temp->next;
        temp->next = del->next;
        unidirectLink::TriQuality(del);
        head->data--;
    }

    void LinkClear() {
        temp = head;
        while (temp) {
            Link<ElemType> *delete_data = temp;
            temp = temp->next;
            TriQuality(delete_data);
        }
        end = head = temp = nullptr;
        isINIT = true;
    }

    int FindData(ElemType data) {
        temp = head;
        for (int i = 1; temp->next; i++) {
            if (temp->next->data == data) return i;
            temp = temp->next;
        }
        return -1;
    }

    ElemType GetData(int i) {
        if (i > head->data) return -1;
        temp = head;
        for (int j = 0; j < i - 1; ++j) temp = temp->next;
        return temp->next->data;
    }

    static std::string ElemTypeToString(const ElemType data) {
        std::ostringstream out;
        out << data;
        return out.str();
    }

    std::string toString() {
        temp = head;
        std::string str = "--------------LINK--------------";
        str += "\ndata: [";
        if (!temp) str += " NULL ";
        else {
            while (temp->next) {
                if (temp != head) str += " ,";
                str += ElemTypeToString(temp->next->data);
                temp = temp->next;
            }
        }
        str += "]\nsize: ";
        if (head) str += ElemTypeToString(head->data);
        else str += "NULL";
        str += "\n--------------END--------------";
        return str;
    }

    friend std::ostream &operator<<(std::ostream &os, unidirectLink &list) {
        os << list.toString();
        return os;
    }

    unidirectLink(int length = 0, bool isHead = false) {
        this->InitLink(length, isHead);
    }
};


#endif //Q_LIST_LIST_H
