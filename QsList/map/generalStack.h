//
// Created by root on 2021/7/27->
//

#pragma once

#include <math.h>

template<typename Elemtype>

class generalStrack {
private:
    template<class ElemType>

    struct Strack{
        ElemType *top;
        ElemType *base;
        int size;
    };

    Strack<Elemtype>* strack;

public:
    generalStrack(int size = 10) {
        if (size < 1) return;
        strack = new Strack<Elemtype>;
        Elemtype* new_base = (Elemtype*) malloc(size * sizeof(Elemtype));
        if (!new_base) return;
        strack->base = new_base;
        new_base = nullptr;
        strack->top = strack->base;
        strack->size = size;
    }

    void push(Elemtype data) {
        if (strack->size == strack->top - strack->base + 1) {
            strack->base = (Elemtype*) realloc(strack->base, (strack->size + 10) * sizeof(Elemtype));
            if (!strack->base) return;
            strack->top = strack->base + (strack->size - 1);
            strack->size += 10;
        }
        *(strack->top) = data;
        strack->top++;
    }

    Elemtype pop() {
        if (strack->top == strack->base && typeid(Elemtype) == typeid(int)) return 0;
        if (strack->top == strack->base) return NULL;
        Elemtype data;
        data = *--(strack->top);
        return data;
    }

    void clear() {
        strack->top = strack->base;
    }

    void del_all() {
        strack->top = nullptr;
        Elemtype* GongJuren = strack->base;
        strack->base = nullptr;
        delete GongJuren;
        strack->size = 0;
    }

    int strackLen() {
        return (strack->top - strack->base);
    }

    int baseConversion(int prev_base, int rear_base) {
        if (typeid(Elemtype) != typeid(int)) return 0;
        int re_base = 0, i = 0;
        if (rear_base == 10) {
            while (strack->top != strack->base) {
                int x_base = pop();
                re_base += x_base * pow(prev_base, i++);
            }
        } else if (rear_base == 8) {
            if (prev_base == 2) {
                i = strackLen() / 3;
                if (i % strackLen() != 0) i++;
                for (int j = 0; j < i; ++j) {
                    int x_base = pow_pop(prev_base, 2);
//                            pop() + pop() * pow(prev_base, 1) + pop() * pow(prev_base, 2);
                    re_base += x_base * pow(10, j);
                }
            }
        }else if (rear_base == 16) {
            if (prev_base == 2) {
                i = strackLen() / 4;
                if (i % strackLen() != 0) i++;
                for (int j = 0; j < i; ++j) {
                    int x_base = (pow_pop(prev_base, 3));
                    re_base += x_base * pow(16, j);
                }
            }
        }
        return re_base;
    }

    int pow_pop(int prev_base, int y) {
        if (y == 0) return pop();
        int re_base = 0;
        re_base += pow_pop(prev_base, y - 1);
        re_base += pop() * pow(prev_base, y);
        return re_base;
    }
};
