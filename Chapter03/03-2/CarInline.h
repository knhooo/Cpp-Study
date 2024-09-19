#ifndef __CARINLINE_H__ //��������� �ߺ����� ������ �ذ��ϱ� ���� ��ũ�� ����
#define __CARINLINE_H__ //��������� �ߺ����� ������ �ذ��ϱ� ���� ��ũ�� ����

#include <iostream>
using namespace std;

//Ŭ���� Car���� ���������� ���Ǵ� �Լ��� �����̹Ƿ� Ŭ���� Car�� ���� ���Ͽ� ����
namespace CAR_CONST {
	enum {
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

//Ŭ������ ����(declaration)
class Car { //Ŭ������ ����
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(const char* ID, int fuel);
	void ShowCarState();//�������� ���
	void Accel();//����, �ӵ� ����
	void Break();//�극��ũ, �ӵ� ����
};

inline void Car::ShowCarState() {
	cout << "������ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << "%" << endl;
	cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;
}

inline void Car::Break() {
	if (curSpeed < CAR_CONST::BRK_STEP) {
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}
#endif //��������� �ߺ����� ������ �ذ��ϱ� ���� ��ũ�� ����