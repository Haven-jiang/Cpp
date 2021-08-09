//
// Created by root on 2021/7/22.
//

#ifndef QLIST_QLIST_H
#define QLIST_QLIST_H
#define LISTINCREMENT 10
#define INITLISTSIZE 10

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>

template<typename ElemType>

class Qlist {
private:
    struct SqList {

        ElemType *elem;
        int length;
        int listsize;
    };
    struct SqList sq_list;
    bool isInit = true;
public:
    void InitList(int listsize) {
        if (isInit) {
            this->sq_list.elem = (ElemType *) malloc(listsize * sizeof(ElemType));
            if (!this->sq_list.elem) return;

            this->sq_list.length = 0;
            this->sq_list.listsize = listsize;
            isInit = false;
        } else RedefineListSize(listsize);
    }

    void InitList() {
        if (isInit) {
            this->sq_list.elem = (ElemType *) malloc(INITLISTSIZE * sizeof(ElemType));//开辟一个存储空间，并把这块存储空间的基地址赋值给elem
            if (!this->sq_list.elem) return;

            this->sq_list.length = 0;
            this->sq_list.listsize = INITLISTSIZE;
        }
    }

    void RedefineListSize(int listsize) {
        try {
            auto *newbase = (ElemType *) realloc(this->sq_list.elem, listsize * sizeof(ElemType));
            if (!newbase) throw -1;
            this->sq_list.elem = newbase;
            this->sq_list.listsize = listsize;
        } catch (int i) {
            std::cout << "重新获取空间失败: 原因可能为程序冲突" << std::endl;
        }
    }

    void AddListSize(int listsize) {
        try {
            auto *newbase = (ElemType *) realloc(this->sq_list.elem,
                                                 ((listsize + this->sq_list.listsize) * sizeof(ElemType)));
            if (!newbase) throw -1;
            this->sq_list.elem = newbase;
            this->sq_list.listsize += listsize;
        } catch (int i) {
            std::cout << "开辟空间空间失败: 原因可能为空间不足" << std::endl;
        }
    }

    int LocateElem(ElemType x) {
        int pos = -1;
        for (int i = 0; i < this->sq_list.length; i++) if (this->sq_list.elem[i] == x) pos = i;
        return pos;
    }

    void ListInsert(int i, ElemType e) { //插入/删除操作 最好情况(i在末尾):O(1)
        if (i < 0 || i > this->sq_list.length + 1) return; //最坏情况(i在开头):O(n)
        if (this->sq_list.length >= this->sq_list.listsize) this->AddListSize(LISTINCREMENT); //平均情况:O((n-1)/2)==O(n)

        ElemType *low, *high;
        low = &(this->sq_list.elem[i]);

        for (high = &(this->sq_list.elem[this->sq_list.length - 1]); high >= low; high--) *(high + 1) = *high;

        *low = e;
        ++this->sq_list.length;
    }

    int getLength() {
        return this->sq_list.length;
    }

    void ListInsert(ElemType e) {
        if (this->sq_list.length >= this->sq_list.listsize) this->AddListSize(1);
        this->sq_list.elem[this->sq_list.length++] = e;
    }

    void ListDelete(int i, ElemType &e) {

        if (i < 0 || i > this->sq_list.length) return;

        ElemType *p_i, *p_j;
        e = *p_i;
        p_j = this->sq_list.elem + this->sq_list.length - 1;
        for (p_i = &(this->sq_list.elem[i]); p_i < p_j; ++p_i) *p_i = *(p_i + 1);
        p_j = nullptr;
        --this->sq_list.length;
    }

//    [[maybe_unused]] Qlist(ElemType, int);
//
//    explicit Qlist(int listsize = 10) {
//        this->InitList(listsize);
//    }

    std::string DoubleToString(const ElemType value) {
        std::ostringstream out;
        out << value;
        return out.str();
    }

    std::string toString() {
        ElemType *pa = &this->sq_list.elem[0], *pb = &this->sq_list.elem[this->getLength() - 1];
        std::string listString = "[";
        for (; pa <= pb; pa++) {
            if (pa != this->sq_list.elem) listString += ", ";
            listString.append(DoubleToString(*pa));
        }
        listString += "]";
        return listString;
    }

    friend std::ostream &operator<<(std::ostream &os, Qlist &qlist) {
        os << "--------------LIST--------------"
           << std::endl
           << "data: "
           << qlist.toString()
           << std::endl
           << "size: "
           << qlist.sq_list.length
           << "\n--------------END--------------\n";
        return os;
    }

    Qlist(int listSize = 15) {
        this->InitList(listSize);
    }
};

//template <typename ElemType>
//
//[[maybe_unused]] Qlist<ElemType>::Qlist(ElemType sqList, int listsize = INITLISTSIZE) {
//    this->InitList(listsize);
//    this->ListInsert(sqList);
//}


#endif //QLIST_QLIST_H
