#include <iostream>

int main(){
	int m = 65, n = 14;
	while(m != n){
		while (m > n) {
			m -= n;
		}while (m < n){
			n -= m;
		}
	}
	std::cout << m;
}
