#include <iostream>

namespace AAA {
	namespace BBB {
		namespace CCC {
			int num1;
			int num2;
		}
	}
}

//AAA::BBB::CCC�� ���� ABC��� ��Ī ����
namespace ABC = AAA::BBB::CCC;

int main(void) {
	ABC::num1 = 10; //AAA::BBB::CCC::num1�� ����.
	ABC::num2 = 20;  //AAA::BBB::CCC::num2�� ����.
	std::cout << ABC::num1 << std::endl;
	std::cout << ABC::num2 << std::endl;
}