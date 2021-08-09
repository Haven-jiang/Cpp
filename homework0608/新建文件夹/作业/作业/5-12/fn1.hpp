#pragma once
#include <iostream>

void fn1() {
	static int n = 0;
	n++;
	std::cout << "n的值为:" << n << std::endl;
} 
