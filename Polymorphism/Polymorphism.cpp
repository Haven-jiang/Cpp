#include <iostream>
using std::cout;
using std::endl;

class A {
	public:
	virtual std::string toString() { return "A"; }
};

class B : public A {
	public:
	std::string toString() { return "B"; }
};

class C : public B {
	public:
	std::string toString() { return "C"; }
};

void print(A* o) {
	cout << o->toString() << endl;
}

void print(A& o){
	cout << o.toString() << endl;
}

int main() {
	A a; B b; C c;
	print(&a); print(&b); print(&c);
	print(a); print(b); print(c);
	return 0;
}
