#include <iostream>
#include <cstring>
using namespace std;

//������� ��Ÿ���� Ŭ����
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
//�������� ��Ÿ���� Ŭ����
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
//�ӽ����� ��Ÿ���� Ŭ����
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
	int salesResult;//�� �Ǹ� ����
	double bonusRatio;//�󿩱� ����
public:
	SalesWorker(char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{  }
	void AddSalesResult(int value) {
		salesResult += value;
	}
	int GetPay() const {//�Լ� �������̵�
		return PermanentWorker::GetPay()//PermanentWorker�� GetPay�Լ� ȣ��
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;//SalesWorker�� GetPay�Լ��� ȣ���
	}
};
class EmployeeHandler {
private:
	//Employee ��ü�� �ּ� ���� �����ϴ� ������� ��ü�� �����Ѵ�.
	//���� Employee Ŭ������ ����ϴ� Ŭ������ ��ü�� �� �迭�� �Բ� ������ �����ϴ�.
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{  }
	void AddEmployee(Employee* emp) {
		//���ڷ� Employee ��ü�� �ּҰ��� �����Ѵ�.
		//���� Employee Ŭ������ ����ϴ� PermanentWorker ��ü�� �ּ� ���� ������ �����ϴ�.
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		//for (int i = 0; i < empNum; i++)
		//	empList[i]->ShowSalaryInfo(); //<= ������ ���� �߻�
	}
	void ShowTotalSalary() const {
		int sum = 0;
		//for (int i = 0; i < empNum; i++)
		//	sum += empList[i]->GetPay(); //<= ������ ���� �߻�
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void) {
	//���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	//���� ���
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("Lee", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	//�̹� �޿� �����ؾ� �� �ݾ��� ����
	handler.ShowAllSalaryInfo();

	//�̹� �޿� �����ؾ� �� �޿��� ����

	handler.ShowTotalSalary();
	return 0;

}