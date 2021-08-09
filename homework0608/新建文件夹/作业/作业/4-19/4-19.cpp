#include <iostream>

using std::cout;
using std::endl;

//Beneath codes usually in CPU.hpp
//
enum numOfCore {
	Single, Double, Four
};

enum Bytes {
	b32, b64
};

enum isHyperthread {
	possess, none
};


class CPU{
public:

	CPU (unsigned clockFrequence, numOfCore type, Bytes length, isHyperthread mode)
		:clockFrequence (clockFrequence), numOfCoreType (type), BytesLen (length), mode (mode){}

	void toString();

friend std::ostream& operator<<(const CPU&, std::ostream&);
friend std::istream& operator>>(CPU&, std::istream&);

private:

	unsigned clockFrequence = 32;
	numOfCore numOfCoreType = Four;
	Bytes BytesLen = b64;
	isHyperthread mode = possess;

};

//Beneath codes usually in CPU.cpp
void CPU::toString () {
	cout << "Frequence:  " << clockFrequence << endl;
	cout << "numOfCore:  ";

	switch ( (unsigned) numOfCoreType){
		case Single:
			cout << "Single-Core"; break;
		case Double:
			cout << "Double-Core"; break;
		case Four:
			cout << "Four-Core"; break;
	}

		cout<<endl;
		cout<<"Bytes:  ";

	switch ((unsigned) BytesLen){
		case b32:
			cout << "32-bits length"; break;
		case b64:
			cout << "64-bits length"; break;
	}

	cout << endl;
	cout << "isHyperthread:  ";

	switch ((unsigned) mode){
		case possess:
			cout << "Possess"; break;
		case none:
			cout << "none"; break;
	}cout << endl;
}


std::ostream& operator<<(const CPU& cpu, std::ostream& out){

	out << "Frequence:  " << cpu.clockFrequence << endl
		<< "numOfCore:  " << cpu.numOfCoreType << endl
		<< "Bytes:  " << cpu.BytesLen << endl
		<< "isHyperthread:  " << cpu.mode << endl;

	return out;
}

std::istream& operator>>(CPU& cpu, std::istream& in){
	in >> cpu.clockFrequence;
		//>> cpu.numOfCoreType >> cpu.BytesLen >> cpu.mode;

	return in;
}


//usually in main.cpp
int main(){
using std::cin;

	// default mode
	
	CPU* c = new CPU(3000000000, Four, b64, possess);
	cout << "Size of Class CPU: " << sizeof (CPU) << endl;
	c->toString ();

	// another mode
	
	CPU anotherOne(3000000000, Four, b64, possess);
	//cin >> anotherOne;
	//cout << anotherOne;
	
	//有时间回来再看看怎么解决吧-_-

	return 0;
}
