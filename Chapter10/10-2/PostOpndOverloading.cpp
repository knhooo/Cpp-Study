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
	Point& operator++() { //전위증가
		xpos += 1;
		ypos += 1;
		return *this;
	}

	const Point operator++(int)//후위증가
	{
		const Point retobj(xpos, ypos);//const Point retobj(*this);
		//반환에 사용할 복사본
		xpos += 1;
		ypos += 1;
		return retobj;//멤버의 값이 증가하기 이전에 만들어둔 복사본을 반환
		//이를 통해 후위증가의 효과를 낸다.
	}
	friend Point& operator--(Point& ref);//전역함수에 대해 friend 선언
	friend const Point operator--(Point& ref, int);
};

Point& operator--(Point& ref) {//전위감소
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}
const Point operator--(Point& ref, int) {//후위감소
	const Point retobj(ref);
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;
}

int main(void) {
	Point pos(3, 5);
	Point cpy;
	cpy = pos--;
	cpy.ShowPosition();
	pos.ShowPosition();

	cpy = pos++;
	cpy.ShowPosition();
	pos.ShowPosition();
	return 0;
}