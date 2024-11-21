/*���� 1
* Point Ŭ������ ���ؼ� ���� ������ �����ϴ� ���·� - ������ �����ε��� �غ���.
* - �����Լ� ������� �����ε�
* - ��� �� - ������ ����� ���� Point ��ü ��ȯ
*/

/*���� 2
* Point Ŭ������ ���ؼ� ���� ������ �����ϴ� ���·� += �����ڿ� -=�����ڸ� �����ε� �غ���.
* - ����Լ� ������� �����ε�
* - ���� 'pos1 += pos2'�� ����� pos1�� ������� ���� pos2�� ������� ����ŭ ��� �� ����
* - ���� 'pos1 -= pos1'�� ����� pos1�� ������� ���� pos2�� ������� ����ŭ ��� �� ����
* - ������ ����� ���� ���� �� ������ pos1�� ��ü�� ��ȯ�ϵ���(�̿��̸� ���������� ��ȯ�ϵ���)
* ������ �����ε�
*/

/*���� 3
* Point Ŭ������ ���ؼ� ���� ������ �����ϴ� ���·� ==�����ڿ� !=�����ڸ� �����ε� �غ���.
* - �� �� �����Լ��� ���·� �����ε�
* - ���� 'pos1 == pos2'�� ����� ��� ����� ���� ���ٸ� true, �׷��� �ʴٸ� false ��ȯ
* - ���� 'pos1 != pos2'�� ����� ��� ����� ���� ���ٸ� false, �׷��� �ʴٸ� true ��ȯ
* ������ ==�� ���� �����ε� �� ������, �̸� �̿��ϴ� ���·� != �����ڸ� �����ε�
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
	//���� 2
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
	//operator+�Լ��� ���� private������ ������ ���
	friend Point operator-(const Point& pos1, const Point& pos2);
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);
};

//���� 1 : -�����ڸ� �����Լ��� ���·� �����ε�
Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

//���� 3 : ==�����ڸ� �����Լ��� ���·� �����ε�
bool operator==(const Point& pos1, const Point& pos2)
{
	if(pos1.xpos == pos2.xpos && pos1.ypos - pos2.ypos)
		return true;
	else
		return false;
}

//���� 3 : !=�����ڸ� �����Լ��� ���·� �����ε�
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