#include <iostream>

void sorted(int x[]){
	for(int i = 0; i < ( sizeof(x) / sizeof(int) ) - 1; i++){
		for(int j = i + 1; j < (sizeof(x) / sizeof(int)); j++){
			if (x[i] > x[j]){
				x[i] = x[i] ^ x[j];
				x[j] = x[i] ^ x[j];
				x[i] = x[i] ^ x[j];
			}
		}
	}
}

int main(int argc, char *argv[]){
	int num[] = {7, 3, 5, 2, 9, 4, 1};
	sorted(num);
	for (int i = 0; i < (sizeof(num)/4); i++){
		std::cout << num[i] << std::endl;
	}
	return 0;
}
