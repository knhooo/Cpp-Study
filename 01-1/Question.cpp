#include<iostream>


int main() {
	//문제 1
	int num1, num2, num3, num4, num5;
	int sum;

	std::cout << "1번째 정수 입력:";
	std::cin >> num1;
	std::cout << "2번째 정수 입력:";
	std::cin >> num2;
	std::cout << "3번째 정수 입력:";
	std::cin >> num3;
	std::cout << "4번째 정수 입력:";
	std::cin >> num4;
	std::cout << "5번째 정수 입력:";
	std::cin >> num5;

	sum = num1 + num2 + num3 + num4 + num5;
	std::cout << "합계: " << sum << std::endl;

	//문제 2
	char name[100];
	char phoneNum[100];

	std::cout << "이름 입력:";
	std::cin >> name;
	
	std::cout << "전화번호 입력:";
	std::cin >> phoneNum;

	std::cout << "이름 : " << name << " 전화번호 : "<< phoneNum<<std::endl;

	//문제 3
	int gugu;
	std::cout << "정수를 입력하세요:";
	std::cin >> gugu;

	for (int i = 1; i < 10; i++) {
		std::cout << gugu << " * " << i << " = " << gugu * i<<std::endl;
	}

	//문제 4
	int price;
	int salary;

	std::cout << "판매 금액을 만원 단위로 입력(-1 to end) : ";
	std::cin >> price;

	while (price != -1) {
	salary = 50 + price * 0.12;

	std::cout << "이번달 급여 : " << salary << std::endl;

	std::cout << "판매 금액을 만원 단위로 입력(-1 to end) : ";
	std::cin >> price;
	} 

	std::cout << "프로그램을 종료합니다."<< std::endl;
	return 0;
}

