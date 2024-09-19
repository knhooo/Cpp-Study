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
	//이름공간을 지정함으로써 이 상수가 어느 영역에서 선언되고 사용되는 상수인지 쉽게 알 수 있다.
	int fuelGauge; //연료량
	int curSpeed;//현재 속도

	void ShowCarState() {
		cout << "소유자ID: " << gamerID << endl; //위에 선언된 gamerID에 접근
		cout << "연료량: " << fuelGauge << "%" << endl;
		cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
	}

	//차의 엑셀을 밟았을 때의 함수
	void Accel() {
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
	void Break() {
		if (curSpeed < CAR_CONST::BRK_STEP) {//위에 선언된 curSpeed에 접근
			curSpeed = 0;
			return;
		}
		curSpeed -= CAR_CONST::BRK_STEP;
	}
};

int main(void) {
	Car run99 = { "run99",100,0 };
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77 = { "sped77",100,0 };
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	return 0;
}