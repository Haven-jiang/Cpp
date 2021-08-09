#include <iostream>
int main(){
	char c;
	for (; (c = getchar() != '\n'); ) std::cout << c;
}
