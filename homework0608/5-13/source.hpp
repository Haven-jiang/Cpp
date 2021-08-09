#pragma once

class X; //为了让编译器在 class Y 中识别 X*

class Y{
public:
	void g(X* pointX); //为了让编译器在 classX 识别友元 Y::g()
};

class X{
private:
	int i;
public:
	X(){i = 0;}
	friend void h(X*);
	friend void Y::g(X*);
	friend class Z;
};

void Y::g(X *pointX){
	pointX -> i++; //原因：X.i 完成定义
}

void h(X* pointX){
	pointX->i += 10;
}

class Z{
public:
	void f(X* pointX){
		pointX += 10;
	}
};
