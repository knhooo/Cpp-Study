#include <iostream>
using namespace std;

namespace CAR_CONST {//이름 공간을 이용해서 상수가 사용되는 영역을 명시
	enum {
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

struct Car {

	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState();//상태정보 출력
	void Accel();//엑셀, 속도 증가
	void Break();//브레이크, 속도 감소
};

void Car::ShowCarState() {
	cout << "소유자ID: " << gamerID << endl; //위에 선언된 gamerID에 접근
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
}

//차의 엑셀을 밟았을 때의 함수
void Car::Accel() {
	if (fuelGauge <= 0) //위에 선언된 fuelGauge에 접근
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}

//브레이크를 밟았을 때의 함수
void Car::Break() {
	if (curSpeed < CAR_CONST::BRK_STEP) {//위에 선언된 curSpeed에 접근
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void) {
	Car run99 = { "run99",100,0 };
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
}