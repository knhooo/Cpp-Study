#include <iostream>
using namespace std;

class First {
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First {
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second {
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main() {
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj;
	//obj는 Second를 상속하는 Third 객체이므로
	//Second형 참조자로 참조가 가능하다.
	sref.FirstFunc();
	sref.SecondFunc();
	//컴파일러는 참조자의 자료형을 가지고 함수의 호출 가능성을 판단하므로
	//First클래스에 정의된 FirstFunc함수과 Second클래스에 정의된 SecondFunc 함수는
	//호출이 가능하지만, Third 클래스에 정의된 ThirdFunc 함수는 호출이 불가능하다.
	sref.SimpleFunc();
	//SimpleFunc는 가상함수이므로, Third클래스에 정의된 SimpleFunc 함수가 호출된다.


	First& fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();
}