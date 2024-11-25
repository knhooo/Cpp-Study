/* 문제 10-3
* main 함수가 보이는 대로 데이터의 입력이 가능하도록,
* 그리고 실행의 예에서 보이는 대로 출력이 이뤄지도록
* >>연산자를 오버로딩하자.
* - cin은 istream 클래스의 객체이다.
* - istream은 이름공간 std 안에 선언되어 있으며,
*   이의 사용을 위해서는 헤더 파일 <iostream>을 포함해야 한다.
*/
#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
	//인자로 전달된 cout의 참조자를 통한 출력을 구성
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

istream& operator>>(istream& is, Point& pos) {
	//인자로 전달된 cout의 참조자를 통한 출력을 구성
	is >> pos.xpos >> pos.ypos;
	return is;
}


int main(void) {
	Point pos1;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos2;
	cout << pos2;
	return 0;
}