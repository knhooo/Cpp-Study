#include <iostream>

using namespace std;
//이름 공간 std에 선언된 것들은
//std라는 이름공간의 선언 없이 접근하겠다는 선언

int main(void) {
	int num = 20;
	cout << "Hello World!" << endl;
	cout << "Hello" << "World!" << endl;
	cout << num << ' ' << 'A';
	cout << ' ' << 3.14 << endl;
	return 0;
}