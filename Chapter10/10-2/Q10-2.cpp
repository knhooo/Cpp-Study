/*문제 1 : 멤버함수의 형태로 오버로딩
* 부호 연산자로서 -는 단항연산자이다. 
*  Point클래스를 대상으로 -연산자를 오버로딩해보자.
* 다음의 문장이 실행되면,
* Point pos2 = -pos1;
* pos2의 멤버변수는 pos1의 멤버변수 값과 다른 부호의 값으로 초기화되도록
* 오버로딩 해보자.
*/
/*문제 2 : 전역함수의 형태로 오버로딩
* ~연산자는 단항연산자로서 비트단위 not의 의미를 갖는다. 
* 1은 0으로, 0은 1로 바꾼다. 이에 우리는 Point객체를 대상으로 다음과 같은
* 연산이 가능하도록 ~연산자를 오버로딩 하고자 한다.
* Point pos2 = ~pos1;
*위의 ~연산의 결과로 반환된 객체의 xpos 멤버에는 pos1의 ypos값이,
*반환된 객체의 ypos 멤버에는 pos1의 xpos 값이 저장되어야 한다.
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
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
	Point operator-() {
		Point pos(-xpos, -ypos);
		return pos;
	}

	friend Point operator~ (const Point&);
};

Point operator~ (const Point &ref) {
	Point pos(ref.ypos, ref.xpos);
	return pos;
}

int main(void) {
	Point pos1(9, -7);
	pos1.ShowPosition();
	Point pos2 = -pos1;
	pos2.ShowPosition();
	(~pos2).ShowPosition();
	pos2.ShowPosition();
	return 0;
}