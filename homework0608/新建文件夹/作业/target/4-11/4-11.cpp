#include<iostream>

using std::cout;
using std::endl;

//һ��box.hpp��
class box {
private:
	double length;
	double width;
	double Area;
public:
	void setArea(double, double);
	double getArea();
    void toString();
};

//һ��box.cpp��
 void box::setArea(double length = 0,double width = 0) {
	 this->length = length;
	 this->width = width;
  }
  
 double box::getArea() {
	 Area = length * width;
     return Area;
 }
 
 void toString() {
     cout << "box's area is: " << this->getArea() << endl;
}
 
//һ��main.cpp��
int main() {
    using std::cin;
    
	box mybox;
    
	double boxLeng,boxWid;
    
    cout << "input length: ";
    cin >> boxLeng;
    cout << "input length: ";
    cin >> boxWid;
    
	mybox.setArea(boxLeng,boxWid);
	mybox.toString();
}
