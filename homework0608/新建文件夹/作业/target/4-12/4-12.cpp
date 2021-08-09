#include <iostream>
#include <typeinfo>

using std::cout, std::endl; //please using -std=c++17, IDE using c++17, too

template <class T> class DataType {
private:
	T data_value;
public:
	DataType(T value){
		this->data_value = value;
	}
	void toString(){
		cout << "type: " << typeid(this->data_value).name() << endl
			<< "value: " << this->data_value << endl;
	}
};

int main(int argc, char *argv[]){

	DataType<int> type_a(66);
	DataType<char> type_b('q');
	DataType<float> type_c(12.54);

	type_a.toString();
	type_b.toString();
	type_c.toString();

	return 0;
}
