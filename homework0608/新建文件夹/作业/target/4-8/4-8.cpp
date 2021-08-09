#include <iostream>
using std::cout;
using std::endl;

class Dog {
private:

	int age;
	int weight;

public:

	Dog(int age = 0, int weight = 0){
		this->age = age;
		this->weight = weight;
	}

	void setAge(int age){
		this->age = age;
	}
	void setWeight(int weight){
		this->weight = weight;
	}

	int getAge(){
		return this->age;
	}
  int getWeight(){
		return this->weight;
	}

	void toString(){
		cout << "Dog's age: " << this->getAge() << endl
			<< "Dog's weight: "<< this->getWeight() << endl;
	}
};
int main() {
	Dog myDog;
	
	int inp_a,inp_w;

	std::cout << "input Dog's age:";
	std::cin >> inp_a;
	std::cout << "input Dog's weight:";
	std::cin >> inp_w;

	myDog.setAge(inp_a);
	myDog.setWeight(inp_w);
	myDog.toString();
}
