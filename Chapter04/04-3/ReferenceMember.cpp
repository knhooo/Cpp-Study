#include <iostream>
using namespace std;

class AAA {
public:
	AAA() {
		cout << "empty object" << endl;
	}
	void ShowYourName() {
		cout << "I'm class AAA" << endl;
	}
};

class BBB {
private:
	AAA& ref;//참조자가 멤버변수로 선언됨
	const int& num;
public:
	BBB(AAA& r, const int& n)
		:ref(r), num(n)//참조자도 이니셜라이저를 이용하면 멤버변수로 선언될 수 있다.
	{//empty
	}
	void ShowYourName() {
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num" << num << endl;
	}
};

int main(void) {
	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();
	return 0;
}