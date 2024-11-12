#include <iostream>
#include <cstring>
using namespace std;

//고용인을 나타내는 클래스
class Employee { 
private:
	char name[100];
public:
	Employee(char* name) {
		strcpy(this->name, name);
	}
	void ShowYourName() const {
		cout << "name: " << name << endl;
	}
};
//정규직을 나타내는 클래스
class PermanentWorker : public Employee {
private:
	int salary;
public:
	PermanentWorker(char* name, int money)
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
	TemporaryWorker(char* name, int pay)
		:Employee(name),workTime(0),payPerHour(pay)
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
	SalesWorker(char* name, int money, double ratio)
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
class EmployeeHandler {
private:
	//Employee 객체의 주소 값을 저장하는 방식으로 객체를 저장한다.
	//따라서 Employee 클래스를 상속하는 클래스의 객체도 이 배열에 함께 저장이 가능하다.
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{  }
	void AddEmployee(Employee* emp) {
		//인자로 Employee 객체의 주소값을 전달한다.
		//따라서 Employee 클래스를 상속하는 PermanentWorker 객체의 주소 값도 전달이 가능하다.
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		//for (int i = 0; i < empNum; i++)
		//	empList[i]->ShowSalaryInfo(); //<= 컴파일 에러 발생
	}
	void ShowTotalSalary() const {
		int sum = 0;
		//for (int i = 0; i < empNum; i++)
		//	sum += empList[i]->GetPay(); //<= 컴파일 에러 발생
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

	//직원 등록
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("Lee", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	//이번 달에 지불해야 할 금액의 정보
	handler.ShowAllSalaryInfo();

	//이번 달에 지불해야 할 급여의 총합

	handler.ShowTotalSalary();
	return 0;

}