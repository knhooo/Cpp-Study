#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point (int x=0, int y=0) : xpos(x),ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class BoundCheckPointArray {
private:
	Point* arr;
	int arrlen;
	BoundCheckPointArray(const BoundCheckPointArray& arr) { }
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { }

public:
	BoundCheckPointArray(int len) : arrlen(len) {
		arr = new Point[len];//인자를 받지 않는 void 생성자의 호출을 통해서 배열 요소를 이루는 객체가 생성되므로,
		//Point 클래스에 정의된 생성자에 설정된 디폴트 값에 의해 객체의 모든 멤버가 0으로 초기화된다.

	}
	Point& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	Point operator[] (int idx) const {//참조값이 아닌, 배열 요소의 값을 단순이 반환한다.
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }//추가된 함수
	~BoundCheckPointArray() {
		delete[] arr;
	}
};

int main(void) {
	BoundCheckPointArray arr(3);
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);
	
	for (int i = 0; i < arr.GetArrLen(); i++) {
		cout << arr[i];
	}
	return 0;
}