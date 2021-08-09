#include <iostream>
#include <algorithm>

int main(){
	int num[] = {4, 7, 9, 3, 6, 1, 17, 2, 4, 8, 8, 9};
	std::sort(num[0], num[sizeof(num)/sizeof(int) - 1]);
	for(int i : num) std::cout << i;
}
