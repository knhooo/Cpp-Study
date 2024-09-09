#include <iostream>

int val = 100; //전역변수

int SimpleFunc(void) {
	int val = 20;
	val += 3;//지역변수 val
	::val += 7;//전역변수 val
	std::cout << "val : " << val << std::endl;
	std::cout << "::val : " << ::val << std::endl;
	return 0;
}

int main() {
	SimpleFunc();
	return 0;
}

