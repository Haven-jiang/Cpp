#include<iostream>

using std::cout;

class Circle {
private:
	double radius;
    
public:
	void setRadius(double n) {
		this->radius = n;
	}
	
	double getArea(){
        return 3.14 * radius * radius;
    }
	
};
int main() {
    using std::cin;
    
	Circle myCirlce;
    
	double cir_r;
    
	cout << "input radius: ";
	cin >> cir_r;
    
	myCirlce.setRadius(cir_r);
    
    cout << myCirlce.getArea() << std::endl;
}
