//
// Created by root on 2021/7/23.
//


#ifndef QSLIST_STATICLINK_H
#define QSLIST_STATICLINK_H

#include <ostream>


template<typename ElemType>
class staticLink {

    struct Link {
        ElemType data;
        int cur;
    };

private:

    Link *node;

    int end = 29;
    int head = 0;
    int current = 1;
    int length = 0;

    bool isINIT = true;

public:

    explicit staticLink(int size = 30) {
        InitLink(size);
    }

    int InitLink(int size = 30) {
        if (!isINIT) {
            std::cout << "注意规则, 您二次了!" << std::endl;
            return -1;
        }
        this->end = size - 1;
        head = 0;
        current = 1;
        node = new Link[size];
        for (int i = 1; i < size - 1; i++) node[i].cur = i + 1;
        node[0].cur = -1;
        node[size - 1].cur = 1;
        isINIT = false;
    }

    int InsertElem(const ElemType &new_elem) {
        if (current == end) return 0;
        int cur =current;
        current = node[current].cur;
        node[cur].data = new_elem;
        node[node[head].cur].cur = cur;
        node[head].cur = cur;
        node[cur].cur = 0;
        length++;
        return 0;
    }

    int InsertElem(int i, const ElemType &new_elem) {
        if (i > current || i < 1) return -1;
        if (current == end) return 0;
        int cur = current;
        current = node[current].cur;
        node[cur].data = new_elem;
        int index = end;
        for (int j = 0; j < i - 1; ++j) {
            index = node[index].cur;
        }
        node[cur].cur = node[index].cur;
        node[index].cur = cur;
        if (i == cur) node[head].cur = cur;
        length++;
        return 0;
    }

    ElemType getData(int i) {
        if (i > current - 1) return  -1;
        int index = end;
        for (int j = 0; j < i; ++j) {
            index = node[index].cur;
        }
        return node[index].data;
    }

    int getLength() {
        return length;
    }

    void clear() {
        for (int i = 1; i < end; i++) {
            node[i].cur = i + 1;
            node[i].data = 0;
        }
        current = 1;
        length = 0;
        node[0].cur = -1;
        node[end].cur = 1;
    }

    int DeleteElem(int i) {
        if (i < 1 || i > current - 1) return 0;  //返回失败

        int index = end;
        for (int j = 0; j < i - 1; ++j) {
            index = node[index].cur;
        }int del = node[index].cur;
        node[index].cur = node[del].cur;
        node[del].cur = current;
        current = del;
        length--;
    }

    std::string elemtypeToString(const ElemType elem) {
        std::ostringstream out;
        out << elem;
        return out.str();
    }

    std::string toString() {
        std::string str;
        str += "data: [";
        int index = node[end].cur;
        for (int i = 0; i < length; ++i) {
            if (index != node[end].cur) str += ", ";
            str += elemtypeToString(node[index].data);
            index = node[index].cur;
        }
        str += ']';
        return str;
    }

    friend std::ostream &operator<<(std::ostream &os, staticLink &link) {
        os << "node: " << link.node << std::endl
           << "size: " << link.end + 1 << std::endl
           << "head: " << link.head << std::endl
           << "length: " << link.length << std::endl
           << link.toString() << std::endl;
        return os;
    }
};

#endif
