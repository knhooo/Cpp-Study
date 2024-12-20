#include <iostream>
using namespace std;

class First {//대입연산자 오버로딩 없음
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0): num1(n1),num2(n2)
	{ }
	void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second {//대입연산자 오버로딩
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3),num4(n4)
	{ }
	void ShowData() { cout << num3 << ", " << num4 << endl; }

	Second& operator= (const Second& ref)//반환형이 참조형
	{
		cout << "Second& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

int main(void) {
	First fsrc(111, 222);
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;
	fcpy = fsrc;//fcpy.operator(fsrc);//디폴트 대입 연산자 호출
	scpy = ssrc;//scpy.operator(ssrc);//정의한 대입 연산자 호출
	fcpy.ShowData();
	scpy.ShowData();

	First fob1, fob2;
	Second sob1, sob2;
	fob1 = fob2 = fsrc;//대입 연산자는 오른쪽에서 왼쪽으로 진행된다.
	sob1 = sob2 = ssrc;

	fob1.ShowData();
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
	return 0;
}