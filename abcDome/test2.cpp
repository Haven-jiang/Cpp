#include <iostream>
int main(){
	int a = 5;
	if (a++ > 5)
		std::cout << a;
	else std::cout << a--;
}
