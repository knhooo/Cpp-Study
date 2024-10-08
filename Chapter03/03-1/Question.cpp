#include <iostream>
using namespace std;

struct Point {
	int xpos;
	int ypos;

	void MovePos(int x, int y)//점의 좌표 이동
	{
		xpos = xpos + x;
		ypos = ypos + y;
	}

	void AddPoint(const Point& pos)//점의 좌표 증가
	{
		xpos = xpos + pos.xpos;
		ypos = ypos + pos.ypos;
	}
	void ShowPosition()//현재 x,y좌표정보 출력
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}


};

int main(void) {
	Point pos1 = { 12,4 };
	Point pos2 = { 20,30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition(); //[5,14]출력

	pos1.AddPoint(pos2);
	pos1.ShowPosition(); //[25,44]출력
	return 0;
}