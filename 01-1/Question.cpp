#include<iostream>


int main() {
	//���� 1
	int num1, num2, num3, num4, num5;
	int sum;

	std::cout << "1��° ���� �Է�:";
	std::cin >> num1;
	std::cout << "2��° ���� �Է�:";
	std::cin >> num2;
	std::cout << "3��° ���� �Է�:";
	std::cin >> num3;
	std::cout << "4��° ���� �Է�:";
	std::cin >> num4;
	std::cout << "5��° ���� �Է�:";
	std::cin >> num5;

	sum = num1 + num2 + num3 + num4 + num5;
	std::cout << "�հ�: " << sum << std::endl;

	//���� 2
	char name[100];
	char phoneNum[100];

	std::cout << "�̸� �Է�:";
	std::cin >> name;
	
	std::cout << "��ȭ��ȣ �Է�:";
	std::cin >> phoneNum;

	std::cout << "�̸� : " << name << " ��ȭ��ȣ : "<< phoneNum<<std::endl;

	//���� 3
	int gugu;
	std::cout << "������ �Է��ϼ���:";
	std::cin >> gugu;

	for (int i = 1; i < 10; i++) {
		std::cout << gugu << " * " << i << " = " << gugu * i<<std::endl;
	}

	//���� 4
	int price;
	int salary;

	std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end) : ";
	std::cin >> price;

	while (price != -1) {
	salary = 50 + price * 0.12;

	std::cout << "�̹��� �޿� : " << salary << std::endl;

	std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end) : ";
	std::cin >> price;
	} 

	std::cout << "���α׷��� �����մϴ�."<< std::endl;
	return 0;
}

