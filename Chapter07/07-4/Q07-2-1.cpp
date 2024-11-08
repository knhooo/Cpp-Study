//����1 ���簢���� �ǹ��ϴ� Square Ŭ������ ���簢���� �ǹ��ϴ� Rectangle Ŭ������ �����ϰ��� �Ѵ�.
// ���簢���� ���簢���� �����̹Ƿ�, ������ ���·� Ŭ������ ��Ӱ��踦 �����ϰ��� �Ѵ�.
#include <iostream>
using namespace std;

class Rectangle {
private :
	int width;
	int length;
public:
	Rectangle(int n1, int n2)
		:width(n1),length(n2)
	{ }
	void ShowAreaInfo() {
		cout << "����: " << width * length << endl;
	}
};

class Square : public Rectangle {
private:
public:
	Square(int num) : Rectangle(num, num)
	{ }
};

int main(void) {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7); 
	sqr.ShowAreaInfo();
	return 0;
}