#include<iostream>

using std::cout, std::endl;// ps: 我认为全局namespace一时爽,当自己定义的 数据 方法 类 的名称与标准库撞车 可就真爽了-_- (尤其是不看报错的小白) (毕竟标准库中的东西不可能全知道)
// -std=c++17 或 -std=c++2a 命令后缀编译

class Boat;//Car 中 friend int getTotalWeight(Car& car, Boat& boat);识别

class Car {
	int weight;
public:
	Car(int weight) {//老师能否教一些命名之类的知识 真的有用
		this->weight = weight;
	}
	friend int getTotalWeight(Car& car, Boat& boat);
};

class Boat {
	int weight;
public:
	Boat(int weight) {
		this->weight = weight;
	}
	friend int getTotalWeight(Car& car, Boat& boat);
};

 int getTotalWeight(Car& car, Boat& boat) {
	return car.weight + boat.weight;
	}
	
 int main() {
	 Car car(4);
	 Boat boat(5);
	 cout << getTotalWeight(car, boat) << endl;
}
