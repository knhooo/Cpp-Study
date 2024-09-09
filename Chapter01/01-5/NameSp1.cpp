#include <iostream>
//존재하는 이름 공간이 다르면 동일한 이름의 함수 및 변수를
//선언하는 것이 가능하다.
namespace BestComImpl {
	void SimpleFunc(void) {
		std::cout << "BestCom이 정의한 함수" << std::endl;
	}
}

namespace ProgComImpl {
	void SimpleFunc(void) {
		std::cout << "ProgCom이 정의한 함수" << std::endl;
	}
}

int main(void) {
	BestComImpl::SimpleFunc();//BestComImpl에 정의된 SimpleFunc 호출
	ProgComImpl::SimpleFunc();//ProgComImpl에 정의된 SimpleFunc 호출
	return 0;
}