#include <iostream>

class Cat{
	private:
	int numbers;
	static int numOfCats;
	public:
	Cat() {
		numOfCats++;
		std::cout << "numberOfCats: " << Cat::getNumberOfCats() << std::endl;
	}
	Cat(int numbers){
		this->numbers = numbers;
		numOfCats++;
		std::cout << "numberOfCats: " << Cat::getNumberOfCats() << std::endl;
	}
	~Cat(){
		numOfCats--;
		std::cout << "numberOfCats: " << Cat::getNumberOfCats() << std::endl;
	}
	static int getNumberOfCats(){
		return numOfCats;
	}
};
int Cat::numOfCats = 0;

int main(){
	for(int i = 0; i < 10; i++){
		Cat c1[i];
		{
			Cat c2(1);
		}
	}
}
