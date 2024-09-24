#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2) 
	:upLeft(x1,y1),lowRight(x2,y2)//��� �̴ϼȶ�����
	//��ü upLeft�� ������������ x1�� y1�� ���ڷ� ���޹޴� �����ڸ� ȣ���϶�.
	//��ü lowRight�� ������������ x2�� y2�� ���ڷ� ���޹޴� �����ڸ� ȣ���϶�.
{
	//empty
}

void Rectangle::ShowRecInfo() const {
	cout << "�� ���: " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "�� �ϴ�: " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl << endl;
}