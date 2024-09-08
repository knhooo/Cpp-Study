#include <iostream>

int Adder(int num1 = 1, int num2 = 2) {
	return num1 + num2;
}

int main(void) {
	std::cout << Adder() << std::endl; //num1, num2 모두 디폴트값
	std::cout << Adder(5) << std::endl; //num1 = 5, num2는 디폴트값
	std::cout << Adder(3, 5) << std::endl; //num1 = 3, num2 = 5
	return 0;
}
