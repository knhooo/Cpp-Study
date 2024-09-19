#include <iostream>
using namespace std;

struct Point {
	int xpos;
	int ypos;

	void MovePos(int x, int y)//���� ��ǥ �̵�
	{
		xpos = xpos + x;
		ypos = ypos + y;
	}

	void AddPoint(const Point& pos)//���� ��ǥ ����
	{
		xpos = xpos + pos.xpos;
		ypos = ypos + pos.ypos;
	}
	void ShowPosition()//���� x,y��ǥ���� ���
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}


};

int main(void) {
	Point pos1 = { 12,4 };
	Point pos2 = { 20,30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition(); //[5,14]���

	pos1.AddPoint(pos2);
	pos1.ShowPosition(); //[25,44]���
	return 0;
}