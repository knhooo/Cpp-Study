//문제1. 앞서 상속관계에 놓여있는 클래스의 생성자 정의 및 호출 방식에 대해 설명하였다.
//이 내용을 바탕으로 다음 클래스에 적적한 생성자를 삽입해보자.
//그리고 이의 확인을 위한 main함수를 적절히 정의해보자.
#include <iostream>
using namespace std;

class Car {
private:
	int gasolineGauge;
public:
	Car(int gauge) : gasolineGauge(gauge)
	{ }
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};
class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int gasoline, int elec)
		: Car(gasoline), electricGauge(elec)
	{ }
	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gasoline, int elec, int water)
		:HybridCar(gasoline,elec),waterGauge(water)
	{ }
	void ShowCurrentGauge() {
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

int main() {
	HybridWaterCar car(100, 200, 300);
	car.ShowCurrentGauge();
	return 0;
}