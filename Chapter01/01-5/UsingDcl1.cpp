#include <iostream>

using std::cin;
using std::cout;
using std::endl;
//이후에 오는 cin,cout,endl은 std::를 명시하지 않더라도
//std::cin/cout/endl을 의미한다는 선언
int main(void) {
	int num = 20;
	cout << "Hello World!" << endl;
	cout << "Hello" << "World!" << endl;
	cout << num << ' ' << 'A';
	cout << ' ' << 3.14 << endl;
	return 0;
}