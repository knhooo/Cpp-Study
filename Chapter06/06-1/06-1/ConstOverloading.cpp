#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{ }
	SoSimple& AddNum(int n) {
		num += n;
		return *this;
	}
	void SimpleFunc() {
		cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc() const {
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const SoSimple& obj) {
	//전달되는 인자를 const 참조자로 받는다.
	obj.SimpleFunc();//17행의 const 멤버 함수 호출
}

int main(void) {
	SoSimple obj1(2);//일반 객체 생성
	const SoSimple obj2(7);//const 객체 생성

	obj1.SimpleFunc();//14행의 일반 멤버 함수 호출
	obj2.SimpleFunc();//17행의 const 멤버 함수 호출

	YourFunc(obj1);
	YourFunc(obj2);
	return 0;
}