#include<iostream>
using namespace std;

//문제 1
void AddOne(int& num) {
	num++;
}
void Toggle(int& num) {
	num = -num;
}

int main() {
	int num = 10;
	AddOne(num);
	cout << "num : " << num <<endl;
	Toggle(num);
	cout << "num : " << num <<endl;
	return 0;
}

//문제 2
void SwapByRef2(int& ref1, int& ref2) {
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main() {
	SwapByRef2(23, 45);
	return 0;
}
////컴파일 에러가 발생하는 이유는??
//// => 매개변수에 참조자가 선언되어있으므로 매개변수의 인자로는 변수가 전달되어야한다.

//문제 3
void SwapPointer(int* (&p1), int* (&p2)) {
	int* tmp = p1;
	p1 = p2;
	p2 = tmp;
}
int main() {
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;
	SwapPointer(ptr1, ptr2);

	cout << "ptr1 : " << *ptr1 << endl;
	cout << "ptr2 : " << *ptr2 << endl;

}