#include <iostream>

int main(void) {
	int val1;
	std::cout << "첫 번째 숫자 입력 : ";
	std::cin >> val1;

	int val2;
	std::cout << "두 번째 숫자 입력 : ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "덧셈결과 : " << result << std::endl;

	double double1;
	std::cout << "double 숫자 입력 : ";
	std::cin >> double1;
	std::cout << "입력한 숫자 : " << double1 << std::endl;

	//문자열 입력 및 출력
	char str[100];
	std::cout << "문자열 입력 : ";
	std::cin >> str;
	std::cout << "입력한 문자열 : " << str;

	return 0;
}