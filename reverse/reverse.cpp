#include <iostream>

int reverse(int num){
	int rev = 0;
	while(num != 0){
		int digit = num % 10;
		num /= 10;
		rev = rev * 10 + digit;
	}
	return rev;
}

int main(){
	int num = 54321;
	num = reverse(num);
	std::cout << num;
}
