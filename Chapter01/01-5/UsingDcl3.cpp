#include <iostream>

namespace AAA {
	namespace BBB {
		namespace CCC {
			int num1;
			int num2;
		}
	}
}

//AAA::BBB::CCC에 대해 ABC라는 별칭 선언
namespace ABC = AAA::BBB::CCC;

int main(void) {
	ABC::num1 = 10; //AAA::BBB::CCC::num1과 같다.
	ABC::num2 = 20;  //AAA::BBB::CCC::num2와 같다.
	std::cout << ABC::num1 << std::endl;
	std::cout << ABC::num2 << std::endl;
}