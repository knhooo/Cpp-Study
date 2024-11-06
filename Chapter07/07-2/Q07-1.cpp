//����1. �ռ� ��Ӱ��迡 �����ִ� Ŭ������ ������ ���� �� ȣ�� ��Ŀ� ���� �����Ͽ���.
//�� ������ �������� ���� Ŭ������ ������ �����ڸ� �����غ���.
//�׸��� ���� Ȯ���� ���� main�Լ��� ������ �����غ���.
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
		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
	}
};

int main() {
	HybridWaterCar car(100, 200, 300);
	car.ShowCurrentGauge();
	return 0;
}