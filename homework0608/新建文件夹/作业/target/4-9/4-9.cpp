#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

class Rectangle {
	int top,left,bottom,right;
public:

	Rectangle(int top, int left, int bottom, int right){
		this->top = top;
		this->left = left;
		this->bottom = bottom;
		this->right = right;
	}

	int getArea() {
		int width = right - left;
		int height = top - bottom;
		return abs(width * height);
	}
};

int main(int argc, char *argv[]){ //shell command input, ide Autocomplete, bu xiang shan le
	Rectangle rect(10, 70, 30, 90);
	cout << "Area:" << rect.getArea() << endl;
	return 0;
}
