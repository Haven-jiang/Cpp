//
// Created by root on 2021/7/24.
//

#ifndef QSLIST_CIRCULARLINK_H
#define QSLIST_CIRCULARLINK_H

#include <ostream>
#include <string>


template<typename ElemType>

class cricularLink : public abstractLink<ElemType> {
private:

    template<typename ElemTypes>
    struct cirLink : public abstractLink<ElemType>::template Link<ElemTypes> {
        ElemTypes data;
        cirLink *next;
    };

    cirLink<int> *rear;
    cirLink<ElemType> *head;
    cirLink<ElemType> *temp;

    [[maybe_unused]] cirLink<ElemType> *getPointer(int node) {
        cirLink<ElemType> *pointer = head;
        for (int i = 0; i < node; ++i) pointer = pointer->next;
        return pointer;
    }

    cirLink<ElemType> *getPointer(cirLink<ElemType> *current, int node) {
        cirLink<ElemType> *pointer = current;
        if (node == -1) pointer = rear->next;
        for (int i = 0; i < node; ++i) pointer = pointer->next;
        return pointer;
    }

public:
    [[maybe_unused]] explicit cricularLink(int length = 0) {
        InitLink(length);
    }

    virtual ~cricularLink() {
        clear();
        temp = nullptr;
        head = nullptr;
        delete temp;
        delete head;
    }

    void InitLink(int size = 0) {
        if (size < 0) return;
        auto *newBase = (cirLink<ElemType> *) malloc(2 * sizeof(cirLink<ElemType>));
        if (!newBase) return;
        rear = newBase;
        rear->data = 0;
        head = rear + sizeof(cirLink<ElemType>);
        rear->next = head;
        temp = head;
        temp->next = head;
        for (int i = 0; i < size; ++i) insert(0);

    }

    void insert(ElemType new_data) {
        while (temp->next != head) temp = temp->next;
        if (rear->data == 0) {
            head->data = new_data;
            rear->data++;
            return;
        }
        auto *newBase = (cirLink<ElemType> *) malloc(sizeof(cirLink<ElemType>));
        newBase->data = new_data;
        newBase->next = head;
        temp->next = newBase;
        temp = temp->next;
        rear->next = newBase;
        newBase = nullptr;
        rear->data++;
    }

    void insert(int i, ElemType new_data) {
        if (i > rear->data || i < 1) return;
        if (i == rear->data) {
            linkInsert(new_data);
            return;
        }
        auto *newBase = (cirLink<ElemType> *) malloc(sizeof(cirLink<ElemType>));
        if (!newBase) return;
        newBase->data = new_data;
        if (i == 1) {
            newBase->next = head->next;
            head->next = newBase;
            head->data = head->data ^ newBase->data;
            newBase->data = head->data ^ newBase->data;
            head->data = head->data ^ newBase->data;
            newBase = nullptr;
            rear->data++;
            return;
        }
        temp = getPointer(i - 2);
        newBase->next = temp->next;
        temp->next = newBase;
        newBase = nullptr;
        rear->data++;
    }

    void LinkDelete(int i) {
        if (i > rear->data || i < 1) return;
        cirLink<ElemType> *del;
        if (!del) return;
        temp = head;
        for (int j = 0; j < i - 1; ++j) temp = temp->next;
        del = temp->next;
        temp->next = del->next;
        delete del;
        del = nullptr;
        rear->data--;
    }

    ElemType getData(int i) {
        if (i > rear->data || i < 1) return NULL;
        temp = head;
        for (int j = 0; j < i; ++j) {
            temp = temp->next;
        }
        return temp->data;
    }

    void clear() {
        temp = head;
        while (head->next != head) {
            cirLink<ElemType> *GongJuren;
            GongJuren = temp->next;
            temp->next = GongJuren->next;
            delete GongJuren;
            rear->data--;
            GongJuren = nullptr;
        }
        temp = head;
    }

    std::string ElemtoString(ElemType elem) {
        std::ostringstream out;
        out << elem;
        return out.str();
    }

    std::string toString() {
        std::string str = "[";
        temp = head;
        for (int i = 0; i < rear->data; i++) {
            if (temp != head) str += ", ";
            str += ElemtoString(temp->data);
            temp = temp->next;
        }
        str += ']';
        return str;
    }

    friend std::ostream &operator<<(std::ostream &os, cricularLink &link) {
        os << "--------------CIRCULAR_LINK--------------\n"
           << "data: " << link.toString() << std::endl
           << "length: " << link.rear->data << std::endl
           << "-------------------END-------------------\n";
        return os;
    }

    // 以下为算法问题 懒得独立出来了

    // 约瑟夫问题
    [[maybe_unused]] void JosephQuestion() {
        if (typeid(ElemType) != typeid(int)) return;
        temp = rear;
        while (head->next != head) {
            temp = temp->next->next;
            std::cout << temp->next->data + "\n";
            del(nullptr);
        }
        std::cout << head->data;
    }

    // 提高挑战难度:编号为1~你的你个人按顺时针方向围坐一圈，每人持有一个密码(正整数，可以自由输入)开始人选
    // 一个正整数作为报数上限值末,从第一个人按顺时针方向自1开始顺序报数，报道末时停止报数。报末的人出列，将
    // 他的密码作为新的末值，从他顺时针方向上的下一个人开始从1报数,如此下去，直至所有人全部出列为止。

    // BTW [一键识图, 多屏协作] KDE connect yyds

    [[maybe_unused]] void AnotherQuestion() {
        if (typeid(ElemType) != typeid(int)) return;
        temp = head;
        temp = rear->next;
        int Pass = 0;
        std::cout << "data: [";
        while (head->next != head) {
            if (Pass > rear->data) Pass = Pass % rear->data;
            if (Pass != 0) temp = getPointer(temp, Pass);
            printf("%d, ", temp->next->data);
            Pass = del_return();
        }
        std::cout << head->data << ']' << std::endl;
    }

    [[maybe_unused]] void magicianQuestion() {
        int i, pass = 0, frequency = -1;
        temp = head;
        while (pass < rear->data) {
            frequency = ++frequency % rear->data;i = 0;
            while (i < frequency || temp->data != 0) {
                if (temp->data == 0) i++;
                temp = temp->next;
            }
            exchange(temp, ++pass);
        }
    }

    [[maybe_unused]] void exchange(cirLink<ElemType> *temp, ElemType new_data) {
        temp->data = new_data;
    }

    [[maybe_unused]] void del() {
        if (typeid(ElemType) != typeid(int)) return;
        cirLink<ElemType> *GongJuren;
        if (head != temp->next) {
            GongJuren = temp->next;
            temp->next = GongJuren->next;
        } else {
            head->data = head->next->data;
            GongJuren = head->next;
            head->next = GongJuren->next;
        }
        delete GongJuren;
        rear->data--;
    }

    [[maybe_unused]] ElemType del_return() {
        if (typeid(ElemType) != typeid(int)) return NULL;
        cirLink<ElemType> *GongJuren;
        ElemType data;
        if (head != temp->next) {
            GongJuren = temp->next;
            temp->next = GongJuren->next;
            if (GongJuren == rear->next) rear->next = temp;
            data = GongJuren->data;
            GongJuren->next = nullptr;
            GongJuren = nullptr;
        } else {
            data = head->data;
            head->data = head->next->data;
            GongJuren = head->next;
            head->next = GongJuren->next;
            GongJuren->next = nullptr;
            GongJuren = nullptr;
        }
        delete GongJuren;
        rear->data--;
        return data;
    }

};

#endif
