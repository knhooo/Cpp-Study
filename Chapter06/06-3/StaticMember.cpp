#include <iostream>
using namespace std;

class SoSimple {
private:
	static int simObjCnt;//SoSimple 객체에 의해서 공유된다.
public:
	SoSimple() {
		//SoSimple의 멤버함수(생성자)내에서는 마치 멤버변수인 것처럼 접근이 가능하다.
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};
int SoSimple::simObjCnt = 0;//static변수는 클래스 외부에서 초기화해야 한다.

class SoComplex {
private:
	static int cmxObjCnt;
public:
	SoComplex() {
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex& copy) {
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main(void) {
	SoSimple sim1;
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();
	return 0;
}