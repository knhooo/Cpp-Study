#include <iostream>

int main(void) {
	int val1;
	std::cout << "ù ��° ���� �Է� : ";
	std::cin >> val1;

	int val2;
	std::cout << "�� ��° ���� �Է� : ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "������� : " << result << std::endl;

	double double1;
	std::cout << "double ���� �Է� : ";
	std::cin >> double1;
	std::cout << "�Է��� ���� : " << double1 << std::endl;

	//���ڿ� �Է� �� ���
	char str[100];
	std::cout << "���ڿ� �Է� : ";
	std::cin >> str;
	std::cout << "�Է��� ���ڿ� : " << str;

	return 0;
}