#include <iostream>
int toLength(std::string str){
	return str.length();
}
int main(){
	std::string s1 = "helloworld";
	std::cout << toLength(s1);
}
