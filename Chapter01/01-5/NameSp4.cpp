#include <iostream>

int val = 100; //��������

int SimpleFunc(void) {
	int val = 20;
	val += 3;//�������� val
	::val += 7;//�������� val
	std::cout << "val : " << val << std::endl;
	std::cout << "::val : " << ::val << std::endl;
	return 0;
}

int main() {
	SimpleFunc();
	return 0;
}

