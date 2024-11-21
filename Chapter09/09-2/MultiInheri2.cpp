#include <iostream>
using namespace std;

class BaseOne
{
public:
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class BaseTwo
{
public:
	void SimpleFunc() { cout << "BaseTwo" << endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void ComplexFunc() {
		//두 클래스에 정의된 멤버함수의 이름이 동일하다.
		BaseOne::SimpleFunc();
		BaseTwo::SimpleFunc();
	}
};

int main(void) {
	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}