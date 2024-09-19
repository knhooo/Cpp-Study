//#ifndef __CAR_H__ //헤더파일의 중복포함 문제를 해결하기 위한 매크로 선언
//#define __CAR_H__ //헤더파일의 중복포함 문제를 해결하기 위한 매크로 선언
//
////클래스 Car에서 제한적으로 사용되는 함수의 선언이므로 클래스 Car와 같은 파일에 선언
//namespace CAR_CONST {
//	enum {
//		ID_LEN = 20,
//		MAX_SPD = 200,
//		FUEL_STEP = 2,
//		ACC_STEP = 10,
//		BRK_STEP = 10
//	};
//}
//
////클래스의 선언(declaration)
//class Car { //클래스의 정의
//private:
//	char gamerID[CAR_CONST::ID_LEN];
//	int fuelGauge;
//	int curSpeed;
//public:
//	void InitMembers(const char* ID, int fuel);
//	void ShowCarState();//상태정보 출력
//	void Accel();//엑셀, 속도 증가
//	void Break();//브레이크, 속도 감소
//};
//
//#endif //헤더파일의 중복포함 문제를 해결하기 위한 매크로 선언