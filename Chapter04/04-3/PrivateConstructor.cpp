#include <iostream>
using namespace std;

class AAA {
private:
	int num;
public:
	//public 생성자 정의.
	//클래스 외부에서는 이 생성자를 기반으로 객체를 생성해야한다.
	AAA() : num(0){}
	//함수 내에서 18행에 정의된 private 생성자를 이용해서 AAA객체를 생성 및 반환한다.
	AAA& CreateInitObj(int n) const {
		AAA* ptr = new AAA(n);
		return *ptr;
	}
	void ShowNum() const { cout << num << endl; }
private:
	AAA(int n):num(n) {}
};

int main(void) {
	AAA base;
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3);
	obj1.ShowNum();

	AAA& obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete& obj1;
	delete& obj2;
	return 0;
}