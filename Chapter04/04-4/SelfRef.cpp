#include <iostream>
using namespace std;

class SelfRef {
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "객체 생성" << endl;
	}
	SelfRef& Adder(int n) {
		num += n;
		return *this;
	}
	SelfRef& ShowTwoNumber() {
		cout << num << endl;
		return *this;
	}
};

int main(void) {
	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2);
	//Adder함수는 객체 자신의 참조 값을 반환한다.
	//참조자 ref는 객체 obj를 참조한다.

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	return 0;
}