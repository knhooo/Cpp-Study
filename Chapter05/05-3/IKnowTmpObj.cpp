#include <iostream>
using namespace std;

class Temporary {
private:
	int num;
public:
	Temporary(int n) :num(n) {
		cout << "create obj: " << num << endl;
	}
	~Temporary() {
		cout << "destroy obj: " << num << endl;
	}
	void ShowTempInfo() {
		cout << "My num is " << num << endl;
	}
};

int main(void) {
	Temporary(100);//임시 객체를 직접 생성
	cout << "*********** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();
	cout << "*********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);//참조값이 반환되므로 참조자로 참조 가능
	cout << "*********** after make!" << endl << endl;
	return 0;
}