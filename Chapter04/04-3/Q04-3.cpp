#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

문제1
class Point {
private:
	int xpos, ypos;
public:
	Point(int x, int y)
		: xpos(x), ypos(y)
	{}
	void ShowPointInfo() const {
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point center;
	int radius;
public:
	Circle(int x, int y, int r)
		: center(x,y)
	{
		radius = r;
	}

	void ShowCircleInfo() const {
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}

};

class Ring {
private:
	Circle one1;
	Circle one2;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2) 
		: one1(x1,y1,r1),one2(x2,y2,r2)
	{ }
	void ShowRingInfo() {
		cout << "Inner Circle Info..." << endl;
		one1.ShowCircleInfo();

		cout << "Outter Circle Info..." << endl;
		one2.ShowCircleInfo();
	}
};

int main(void) {
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}



문제2
namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int pos) {
		switch (pos) {
		case CLERK :
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
			break;
		}
	}
}

class NameCard {
private:
	char* name;
	char* compName;
	char* tel;
	int position;
public:
	NameCard(char* n, char* c, char* num, int pos)
		:position(pos)
	{
		this->name = new char[strlen(name) + 1];
		this->compName = new char[strlen(compName) + 1];
		this->tel = new char[strlen(tel) + 1];
		strcpy(this->name, name);
		strcpy(this->compName, compName);
		strcpy(this->tel, tel);
	}
	void ShowNameCardInfo() {
		cout << "이름: "<< name <<endl;
		cout << "회사: "<< compName <<endl;
		cout << "전화번호: "<< tel <<endl;
		cout << "직급: "; COMP_POS::ShowPositionInfo(position);
	}
	~NameCard() {
		delete[] name;
		delete[] compName;
		delete[] tel;
	}
};

int main(void) {
	NameCard manClerck("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerck.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}