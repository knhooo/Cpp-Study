/*문제 1
* Point 클래스에 대해서 다음 조건을 만족하는 형태로 - 연산자 오버로딩을 해보자.
* - 전역함수 기반으로 오버로딩
* - 멤버 별 - 연산의 결과를 담은 Point 객체 반환
*/

/*문제 2
* Point 클래스에 대해서 다음 조건을 만족하는 형태로 += 연산자와 -=연산자를 오버로딩 해보자.
* - 멤버함수 기반으로 오버로딩
* - 연산 'pos1 += pos2'의 결과로 pos1의 멤버변수 값이 pos2의 멤버변수 값만큼 멤버 별 증가
* - 연산 'pos1 -= pos1'의 결과로 pos1의 멤버변수 값이 pos2의 멤버변수 값만큼 멤버 별 감소
* - 연산의 결과로 값이 증가 및 감소한 pos1의 객체를 반환하도록(이왕이면 참조형으로 반환하도록)
* 연산자 오버로딩
*/

/*문제 3
* Point 클래스에 대해서 다음 조건을 만족하는 형태로 ==연산자와 !=연산자를 오버로딩 해보자.
* - 둘 다 전역함수의 형태로 오버로딩
* - 연산 'pos1 == pos2'의 결과로 모든 멤버의 값이 같다면 true, 그렇지 않다면 false 반환
* - 연산 'pos1 != pos2'의 결과로 모든 멤버의 값이 같다면 false, 그렇지 않다면 true 반환
* 연산자 ==를 먼저 오버로딩 한 다음에, 이를 이용하는 형태로 != 연산자를 오버로딩
*/
#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	//문제 2
	Point& operator+=(const Point &ref) {
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point& operator-=(const Point ref) {
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}
	//operator+함수에 대해 private영역의 접근을 허용
	friend Point operator-(const Point& pos1, const Point& pos2);
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);
};

//문제 1 : -연산자를 전역함수의 형태로 오버로딩
Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

//문제 3 : ==연산자를 전역함수의 형태로 오버로딩
bool operator==(const Point& pos1, const Point& pos2)
{
	if(pos1.xpos == pos2.xpos && pos1.ypos - pos2.ypos)
		return true;
	else
		return false;
}

//문제 3 : !=연산자를 전역함수의 형태로 오버로딩
bool operator!=(const Point& pos1, const Point& pos2)
{
	return !(pos1 == pos2);
}

int main(void) {
	Point pos1(20, 30);
	Point pos2(5, 7);
	Point pos3(5, 7);
	
	(pos1 - pos2).ShowPosition();
	(pos2 += pos3).ShowPosition();

	if (pos2 == pos3)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;

	(pos2-=pos3).ShowPosition();
	if (pos2 != pos3)
		cout << "not equal" << endl;
	else
		cout << "equal" << endl;
	return 0;
}