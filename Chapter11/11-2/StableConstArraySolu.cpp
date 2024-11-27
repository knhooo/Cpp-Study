#include<iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray {
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }

public:
	BoundCheckIntArray(int len) : arrlen(len) {
		arr = new int[len];
	}
	int& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int operator[] (int idx) const {//참조값이 아닌, 배열 요소의 값을 단순이 반환한다.
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }//추가된 함수
	~BoundCheckIntArray() {
		delete[] arr;
	}
};

void ShowAllData(const BoundCheckIntArray& ref) {
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl;//const 참조자를 이용한 연산이므로 const 함수가 호출됨
}

int main(void) {
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;//const로 선언되지 않은 arr을 이용한 연산이다.

	ShowAllData(arr);
	return 0;
}