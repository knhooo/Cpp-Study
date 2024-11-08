//문제1 정사각형을 의미하는 Square 클래스와 직사각형을 의미하는 Rectangle 클래스를 정의하고자 한다.
// 정사각형은 직사각형의 일종이므로, 다음의 형태로 클래스의 상속관계를 구성하고자 한다.
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
		cout << "면적: " << width * length << endl;
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