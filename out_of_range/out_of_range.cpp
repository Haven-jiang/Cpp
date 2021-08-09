#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main(){
	std::vector <char> v{'a' , 'b' , 'c' , 'd' , 'e'};
	try {
		for (int i=0 ; i<=5 ; i++){
			cout << v[i] << endl;
			cout << v.at(i) << endl;
		}
	}catch (std::out_of_range& e){
		cout << "Exception: " << e.what() << endl;
	}
}
