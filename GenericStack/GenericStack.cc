#include <iostream>
#include <string>
#include "Stack.hpp"

int main(){
    Stack<char> c;
    std::string S{"Hello, World!"};
    
    for(auto i : S){
        c.push(i);
    }

    while(c.empty() == false){
        std::cout << c.pop();
    }
}