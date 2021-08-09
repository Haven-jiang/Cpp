//
// Created by root on 2021/7/27.
//

#pragma once
#include <ctype.h>
#include <stdlib.h>

template<typename ElemType>

class chainStrack{
private:
    template<class ElemTypes>
    struct Strack{
        Strack *next;
        ElemTypes data;
    };

    Strack<ElemType> *top;
    Strack<ElemType> *base;
    int length;

public:
    chainStrack() {
        base = (Strack<ElemType>*) malloc(sizeof(Strack<ElemType>));
        if (!base) return;
        top = base;
        length = 0;
    }

    void push(ElemType data) {
        top->data = data;
        top->next = new Strack<ElemType>;
        top = top->next;
        top->next = nullptr;
        length++;
    }

    ElemType pop() {
        if (top == base) return top->data;
        Strack<ElemType>* temp = base;
        while (temp->next != top) temp = temp->next;
        top = temp;
        temp = temp->next;
        delete temp;
        top->next = nullptr;
        length--;
        return top->data;
    }

    void clear() {
        top = base;
        while (top != nullptr) {
            Strack<ElemType>* temp = top->next;
            if (temp == nullptr) {
                temp = top;
                top = base = nullptr;
            }else if (temp->next == nullptr) top->next = nullptr;
            else top->next = temp->next;
            delete temp;
        }
    }

    ElemType repolishExpression() {

        std::string num;
        char in_put;
        ElemType result;

        while (in_put != '#') {

            std::cin >> in_put;

            while (isdigit(in_put) || in_put == '.') {
                num += in_put;
                scanf("%c", &in_put);
                if (in_put == ' ') {
                    double number = atof(num.c_str());
                    push(number);
                    num = '0';
                }
            }
            switch (in_put) {
                case '+':
                    push(pop() + pop());break;
                case '-':
                    push(0 - pop() + pop());break;
                case '*':
                    push(pop() * pop());break;
                case '/':
                    ElemType prev = pop(), rear = pop();
                    if (prev == 0) {
                        std::cout << "error: divisor=0!";
                        return 0;
                    }
                    push(rear / prev);break;
            }
        }
        result = pop();
        return result;
    }

    void toRepolish() {
        char input;
        char num[15];
        int i = 0;

        while (input != '#') {

            std::cin >> input;

            while (isdigit(input) || input == '.') {
                num[i++] = input;
                num[i] = ' ';
                num[i+1] = '\0';
                scanf("%c", &input);
                if (!isdigit(input) || input != '.') {
                    std::cout << num;
                    i = 0;
                    break;
                }
            }
            if (input == '(') push(input);
            else if (input == ')') {
                char symbol = pop();
                while (symbol != '(') {
                    std::cout << symbol;
                    symbol = pop();
                }
            } else if (input == '*' || input == '/') {
                char symbol = pop();
                if (symbol == '*' || symbol == '/') std::cout << symbol;
                else if (symbol == '+' || symbol == '-') push(symbol);
                push(input);
            } else if (input == '+' || input == '-') {
                char symbol = pop();
                push(symbol);
                if (symbol != '(') while (top != base) std::cout << pop();
                push(input);
            }
        }while (top != base) std::cout << pop();
        std::cout << std::endl;
    }
};