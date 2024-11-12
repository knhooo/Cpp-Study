#include <iostream>
using namespace std;

class First {
public:
	virtual void MyFunc() { cout << "FirstFunc" << endl; }
};

class Second : public First {
public:
	//First 클래스의 MyFunc가 virtual로 선언되었으니 
	//오버라이딩하는 함수에는 virtual선언을 추가하지 않아도 가상함수가 된다.
	virtual void MyFunc() { cout << "SecondFunc" << endl; }
};

class Third : public Second {
public:
	//위와 마찬가지이다.
	//그러나 virtual 선언을 넣어서 가상함수임을 보여주는 것이 좋다.
	virtual void MyFunc() { cout << "ThirdFunc" << endl; }
};

int main() {
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;
}