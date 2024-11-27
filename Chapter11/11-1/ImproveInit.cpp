#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA(int n = 0) : num(n) {
		cout << "AAA(int n = 0)" << endl;
	}
	AAA(const AAA& ref) : num(ref.num) {
		cout << "AAA(const AAA& ref)" << endl;
	}
	AAA& operator=(const AAA& ref) {
		num = ref.num;
		cout << "operator=(const AAA& ref)" << endl;
		return *this;
	}
};

class BBB {
private:
	AAA mem;
public:
	BBB(const AAA& ref) : mem(ref) {  }//이니셜라이저로 멤버 초기화
};

class CCC {
private:
	AAA mem;
public:
	CCC(const AAA& ref) { mem = ref; }//대입연산으로 멤버 초기화
};

int main(void) {
	AAA obj1(12);
	cout << "*********************" << endl;
	BBB obj2(obj1);
	cout << "*********************" << endl;
	CCC obj3(obj1);
	return 0;

}