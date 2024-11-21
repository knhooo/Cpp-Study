#include <iostream>
using namespace std;

class BaseOne
{
public:
	void SimpleFuncOne() { cout << "BaseOne" << endl; }
};

class BaseTwo
{
public:
	void SimpleFuncTwo() { cout << "BaseTwo" << endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void ComplexFunc() {
		SimpleFuncOne();//BaseOne 클래스의 멤버함수
		SimpleFuncTwo();//BaseTwo 클래스의 멤버함수
	}
};

int main(void) {
	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}