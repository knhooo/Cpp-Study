//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//namespace CAR_CONST {//이름 공간을 이용해서 상수가 사용되는 영역을 명시
//	enum {
//		ID_LEN = 20,
//		MAX_SPD = 200,
//		FUEL_STEP = 2,
//		ACC_STEP = 10,
//		BRK_STEP = 10
//	};
//}
//
//class Car { //클래스의 정의
//private : //이어서 등장하는 변수와 함수는 private에 해당하는 범위 내에서(클래스 내에서만) 접근이 가능하다.
//	char gamerID[CAR_CONST::ID_LEN];
//	int fuelGauge;
//	int curSpeed;
//public ://이어서 등장하는 변수와 함수는 public에 해당하는 범위 내에서(어디서든)접근이 가능하다.
//	void InitMembers(const char* ID, int fuel);
//	void ShowCarState();//상태정보 출력
//	void Accel();//엑셀, 속도 증가
//	void Break();//브레이크, 속도 감소
//};
//
////클래스 안에 선언된 변수의 초기화를 목적으로 정의된 함수
////변수가 모두 private으로 선언되어 main함수에서 접근이 불가능하다.
////그러나 이 함수는 동일 클래스 내에 정의된 함수이므로 접근이 가능하다.
////이 함수는 public으로 선언되어 main함수에서 호출이 가능하다.
////따라서 main함수에서는 이 함수의 호출을 통해서 클래스 안에 선언된 변수를 초기화할 수 있다.
//void Car::InitMembers(const char* ID, int fuel) {
//	strcpy(gamerID, ID);
//	fuelGauge = fuel;
//	curSpeed = 0;
//}
//
//void Car::ShowCarState() {
//	cout << "소유자ID: " << gamerID << endl;
//	cout << "연료량: " << fuelGauge << "%" << endl;
//	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
//}
//
////차의 엑셀을 밟았을 때의 함수
//void Car::Accel() {
//	if (fuelGauge <= 0)
//		return;
//	else
//		fuelGauge -= CAR_CONST::FUEL_STEP;
//
//	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
//		curSpeed = CAR_CONST::MAX_SPD;
//		return;
//	}
//	curSpeed += CAR_CONST::ACC_STEP;
//}
//
////브레이크를 밟았을 때의 함수
//void Car::Break() {
//	if (curSpeed < CAR_CONST::BRK_STEP) {
//		curSpeed = 0;
//		return;
//	}
//	curSpeed -= CAR_CONST::BRK_STEP;
//}
//
//int main(void) {
//	Car run99;
//	//함수가 모두 public으로 선언되었기 때문에 함수 호출이 가능하다.
//	run99.InitMembers("run99", 100);
//	//const char에서 char*로 변환할 수 없다는 오류 발생 
//	//void InitMembers(char* ID, int fuel);에서 void InitMembers(const char* ID, int fuel);로 수정
//	run99.Accel();
//	run99.Accel();
//	run99.Accel();
//	run99.ShowCarState();
//	run99.Break();
//	run99.ShowCarState();
//	return 0;
//}