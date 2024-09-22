#include <iostream>
using namespace std;

class Point {
public://public으로 선언되어 어디서든 접근이 가능하다.
	int x;//x좌표의 범위는 0이상 100이하
	int y;//y좌표의 범위는 0이상 100이하
};

class Rectangle {//직사각형을 표현
public: 
	//클래스의 멤버로 객체를 둘 수 있다.
	Point upLeft;
	Point lowRight;
public:
	void ShowRecInfo() {
		cout << "좌 상단: " << '[' << upLeft.x << ", ";
		cout << upLeft.y << ']' << endl;
		cout << "우 하단: " << '[' << lowRight.x << ", ";
		cout << lowRight.y << ']' << endl << endl;
	}
};

int main(void) {
	//직사각형을 표현할 두 개의 Point 객체를 생성
	//멤버변수가 public으로 선언되면, 구조체 변수를 초기하듯이 초기화가 가능하다.
	Point pos1 = { -2, 4 };
	Point pos2 = { 5, 9 };
	//위에서 생성한 Point객체를 이용하여 Rectangle 객체를 생성 및 초기화
	Rectangle rec = { pos2, pos1 };
	rec.ShowRecInfo();
	return 0;
}