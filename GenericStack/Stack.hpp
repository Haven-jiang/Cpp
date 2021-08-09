#pragma once
#define N 100

template<typename T>

class Stack{
private:
    T elements[N];
    int size{0};
public:
    Stack();
    bool empty();
    T peek();
    T push(T value);
    T pop();
    int getSize();
};


template <typename T>
Stack<T>::Stack(){
    size =0;
    for(auto &i : elements){
        i = 0;
    }
}

template <typename T>
bool Stack<T>::empty(){
    return size == 0 ? true : false;
}

template <typename T>
T Stack<T>::peek(){
    return elements[size - 1];
}

template <typename T>
T Stack<T>::push(T value){
    elements[size] = value;
    size++;
    return elements[size - 1];
}

template <typename T>
T Stack<T>::pop(){
    T temp = elements[size - 1];
    elements[size - 1] = 0;
    size--;
    return temp;
}

template <typename T>
int Stack<T>::getSize(){
    return size;
}