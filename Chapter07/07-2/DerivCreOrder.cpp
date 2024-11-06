#include <iostream>
using namespace std;

class SoBase {
private:
	int baseNum;
public:
	SoBase() :baseNum(20) {
		cout << "SoBase()" << endl;
	}
	SoBase(int n) : baseNum(n) {
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData() {
		cout << baseNum << endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30)
	{//기초 클래스의 생성자 호출 없음
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) : derivNum(n)
	{//기초 클래스의 생성자 호출 없음
		cout << "SoDerived(int n)" << endl;
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
	{//기초 클래스의 생성자 호출 명시됨
		cout << "SoDerived(int n1, int n2)" << endl;
	}
	void ShowDerivData() {
		ShowBaseData();
		cout << derivNum << endl;
	}
};

int main(void) {
	cout << "case1..... " << endl;
	SoDerived dr1;
	dr1.ShowDerivData();
	cout << "---------------------" << endl;
	cout << "case2..... " << endl;
	SoDerived dr2(12);
	dr2.ShowDerivData();
	cout << "---------------------" << endl;
	cout << "case3..... " << endl;
	SoDerived dr3(23,24);
	dr3.ShowDerivData();
	cout << "---------------------" << endl;
}