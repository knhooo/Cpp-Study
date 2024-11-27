#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

typedef Point* POINT_PTR;

class BoundCheckPointPtrArray {
private:
	POINT_PTR* arr;
	int arrlen;
	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { }

public:
	BoundCheckPointPtrArray(int len) : arrlen(len) {
		arr = new POINT_PTR[len];//인자를 받지 않는 void 생성자의 호출을 통해서 배열 요소를 이루는 객체가 생성되므로,
		//Point 클래스에 정의된 생성자에 설정된 디폴트 값에 의해 객체의 모든 멤버가 0으로 초기화된다.

	}
	POINT_PTR& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR operator[] (int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }//추가된 함수
	~BoundCheckPointPtrArray() {
		delete[] arr;
	}
};

int main(void) {
	BoundCheckPointPtrArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++) {
		cout << *(arr[i]);
	}
	//객체의 주소 값을 저장할 경우, 깊은 복사인지 얕은 복사인지 신경쓰지 않아도 된다.

	delete arr[0];
	delete arr[1];
	delete arr[2];

	return 0;
}