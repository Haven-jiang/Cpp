#include <stdio.h>
	//函数
	int function (int a = 1, char b = 'c', double c = 3.0){
		//do something
		return 1;
	}
	//这个void应该就是缺省类型
	void function1(){

	}
int main(){
	char c = 'a';
	//printf("%c",c);
	//putchar的使用
	//putchar(c);
	char c2[6] = "qwert";
	//printf("%s", c2);
	//putchar(c);

	int returnint = function(1);

	int x = 12;int ch = 97;
	printf("%x, %o, ", ch, ch, x);
	printf("x = %% d \n", x);

}
//Brackets are not allowed here; to declare an array, place the brackets after the name (fix available)
//[clang: brackets_go_after_unqualified_id]
