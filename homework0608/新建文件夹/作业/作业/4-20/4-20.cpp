#include<iostream>

using std::cout;
using std::endl;

class Complex {
private:
	double Real = 0, Imaginary = 0;
public:
	Complex(double Real, double Imaginary) : Real(Real), Imaginary(Imaginary){}
	Complex(double Real) : Real(Real) {}

	void add(Complex c2) {
		this->Real += c2.Real;
		this->Imaginary += c2.Imaginary;
	}
	void show() {
		cout << Real << "+" << Imaginary << "i" << endl;
	}

	Complex& operator+(const Complex& c){
		this->Real += c.Real;
		this->Imaginary += c.Imaginary;
		return *this;
   }

};
int main() {
	Complex c1(3, 5);
	Complex c2 = 4.5;
	c1 = c1 + c2;
	c1.show();
}
