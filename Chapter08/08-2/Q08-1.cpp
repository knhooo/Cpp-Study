/*예제 EmployeeManager4.cpp를 확장하여 다음 특성에 해당하는 ForeignSalesWorker
클래스를 추가로 정의해보자.
"영업직 직원 중 일부는 오지산간으로 시장개척을 진행하고 있다.
이러한 직원들을 대상으로 별도의 위험 수당을 지급하고자 한다."
위험수당의 지급 방식은 다음과 같이 나뉘며, 한번 결정된 직원의 위험노출도는
변경되지 않는다.(const 멤버변수 선언 유도)
다음 main 함수와 함께 동작하도록 ForeignSalesWorker 클래스를 정의하기 바라며,
Employee 클래스는 객체 생성이 불가능한 추상 클래스로 정의하라.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//고용인을 나타내는 클래스
class Employee {
private:
	char name[100];
public:
	Employee(const char* name) {
		strcpy(this->name, name);
	}
	void ShowYourName() const {
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const //가상함수
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const //가상함수
	{  }
};
//정규직을 나타내는 클래스
class PermanentWorker : public Employee {
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		:Employee(name), salary(money)
	{  }
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};
//임시직을 나타내는 클래스
class TemporaryWorker : public Employee {
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay)
		:Employee(name), workTime(0), payPerHour(pay)
	{  }
	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() const {
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};
class SalesWorker : public PermanentWorker {
private:
	int salesResult;//월 판매 실적
	double bonusRatio;//상여금 비율
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{  }
	void AddSalesResult(int value) {
		salesResult += value;
	}
	int GetPay() const {//함수 오버라이딩
		return PermanentWorker::GetPay()//PermanentWorker의 GetPay함수 호출
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;//SalesWorker의 GetPay함수가 호출됨
	}
};
class ForeignSalesWorker : SalesWorker
{
private:
public:
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "risk pay: " <<  << endl << endl;
		cout << "sum: " <<  << endl << endl;
	}
};
class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{  }
	void AddEmployee(Employee* emp) {

		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo(); //<= 컴파일 에러 해결
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay(); //<= 컴파일 에러 해결
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void) {
	//직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;

	//해외 영업직 등록
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(70000); //영업실적 70000
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(70000); //영업실적 70000
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(70000); //영업실적 70000
	handler.AddEmployee(fseller3);

	//이번 달에 지불해야 할 금액의 정보
	handler.ShowAllSalaryInfo();

	return 0;

}