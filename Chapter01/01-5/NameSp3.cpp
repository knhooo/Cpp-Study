#include <iostream>
//함수의 선언은 반드시 이름 공간 내부에
namespace BestComImpl {
	void SimpleFunc(void);
}
//선언된 이름공간의 이름이 동일하다면
//동일한 이름공간으로 간주한다.
namespace BestComImpl {
	void PrettyFunc(void);
}

namespace ProgComImpl {
	void SimpleFunc(void);
}

int main(void) {
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}

//정의를 별도로 할 때에는 이름 공간 명시 필요
void BestComImpl::SimpleFunc(void) {
	std::cout << "BestCom이 정의한 함수" << std::endl;
	PrettyFunc();
	//이름공간을 명시하지 않은 상태에서 호출 가능
	ProgComImpl::SimpleFunc(); //다른 이름공간의 함수 호출
}

void BestComImpl::PrettyFunc(void) {
	std::cout << "So Pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc(void) {
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}