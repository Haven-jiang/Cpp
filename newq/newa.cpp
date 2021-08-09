#include <stdio.h>
int main(){
	int i = 0, n = 0;
	for (i++; i < 10, i++; ++i, n++){
		printf("%d%d\t", i, n);
	}
}
