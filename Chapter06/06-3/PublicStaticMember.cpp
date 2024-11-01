#include <iostream>
using namespace std;

class SoSimple {
public://static 멤버변수가 public으로 선언되었다.
	static int simObjCnt;
public:
	SoSimple() {
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;

int main(void) {
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	//SoSimple 객체가 하나도 생성하지 않은 상태이지만,
	//클래스의 이름을 이용해서 simObjCnt에 접근하고 있다.
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;

	return 0;
}