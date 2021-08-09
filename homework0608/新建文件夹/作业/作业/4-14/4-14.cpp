#include <iostream>

using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Tree {
private:
	int ages,years;
public:
	Tree(int ages = 0) {
		this->ages = ages;
	}
	void grow(int years) {
		this->years = years;
	}
	void operateAge() {
		this->ages = ages + years;
	}
	friend istream &operator>> (istream &in, Tree& t){
		in >> t.ages >> t.years;
		return in;
	}
	friend ostream &operator<< (ostream& out, Tree &t){
		t.operateAge();
		out << "This tree age is: " << t.ages << endl;
		return out;
	}
};
int main() {
	using std::cin;
	Tree thisTree;
	cout << "How old is this tree? And how many more years have passed? : ";
	cin >> thisTree;
	cout << thisTree;
}
