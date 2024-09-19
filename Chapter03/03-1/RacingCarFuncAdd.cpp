#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

//구조체 안에 함수를 삽입
//함수가 구조체 내에 삽입되면서 구조체 내에 선언된 변수에 직접 접근이 가능해졌다.
struct Car {
	char gamerID[ID_LEN];//소유자 ID
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
			fuelGauge -= FUEL_STEP;

		if (curSpeed + ACC_STEP >= MAX_SPD) {
			curSpeed = MAX_SPD;
			return;
		}
		curSpeed += ACC_STEP;
	}

	//브레이크를 밟았을 때의 함수
	void Break() {
		if (curSpeed < BRK_STEP) {//위에 선언된 curSpeed에 접근
			curSpeed = 0;
			return;
		}
		curSpeed -= BRK_STEP;
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