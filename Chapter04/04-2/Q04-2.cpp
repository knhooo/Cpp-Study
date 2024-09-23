#include <iostream>
using namespace std;
//Point 클래스를 기반으로 하여 원을 의미하는 Circle 클래스를 정의하자.
class Point {
private:
	int xpos, ypos;
public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point center;
	int radius;
public:
	void Init(int x,int y,int r ) {
		center.Init(x,y);
		radius = r;
	}

	void ShowCircleInfo() const {
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}

};

class Ring {
private:
	Circle one1;
	Circle one2;
public:
	void Init(int x1,int y1,int r1, int x2, int y2, int r2) {
		one1.Init(x1,y1,r1);
		one2.Init(x2,y2,r2);
	}
	void ShowRingInfo() {
		cout << "Inner Circle Info..." << endl;
		one1.ShowCircleInfo();

		cout << "Outter Circle Info..." << endl;
		one2.ShowCircleInfo();
	}
};

int main(void) {
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}