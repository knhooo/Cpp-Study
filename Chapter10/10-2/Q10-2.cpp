/*���� 1 : ����Լ��� ���·� �����ε�
* ��ȣ �����ڷμ� -�� ���׿������̴�. 
*  PointŬ������ ������� -�����ڸ� �����ε��غ���.
* ������ ������ ����Ǹ�,
* Point pos2 = -pos1;
* pos2�� ��������� pos1�� ������� ���� �ٸ� ��ȣ�� ������ �ʱ�ȭ�ǵ���
* �����ε� �غ���.
*/
/*���� 2 : �����Լ��� ���·� �����ε�
* ~�����ڴ� ���׿����ڷμ� ��Ʈ���� not�� �ǹ̸� ���´�. 
* 1�� 0����, 0�� 1�� �ٲ۴�. �̿� �츮�� Point��ü�� ������� ������ ����
* ������ �����ϵ��� ~�����ڸ� �����ε� �ϰ��� �Ѵ�.
* Point pos2 = ~pos1;
*���� ~������ ����� ��ȯ�� ��ü�� xpos ������� pos1�� ypos����,
*��ȯ�� ��ü�� ypos ������� pos1�� xpos ���� ����Ǿ�� �Ѵ�.
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