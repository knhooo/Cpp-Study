//Accout 클래스의 멤버함수 중 일부를 const로 선언하면서
//BankingSystem의 버전을 업그레이드 시키겠다.
//const로 선언이 가능한 모든 멤버함수를 const로 선언하자.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Account {
private:
	int id;//계좌번호
	char* name;//이름
	int money;//잔액

public:
	Account(int pid, char* pname, int pmoney)//생성자
		:id(pid), money(pmoney)
	{
		name = new char[strlen(pname) + 1];
		strcpy(name, pname);
	}
	Account(const Account& ref)//복사 생성자
		:id(ref.id), money(ref.money)
	{
		name = new char[strlen(ref.name) + 1];
		strcpy(name, ref.name);
	}
	 int GetID() const {
		return id;
	}
	char* GetName() const {
		return name;
	}
	int GetMoney() const {
		return money;
	}
	int Withdraw(int num) {
		if (num > money) {
			return 0;
		}
		money -= money;
		return money;
	}
	void Deposit(int num) {
		money += num;
	}
	~Account() {//소멸자
		delete[]name;
	}
};

Account* AccountArr[100];
int accNum = 0;

void ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입     금" << endl;
	cout << "3. 출     금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << " " << endl;
}

void CreateAccount() {
	int id;
	char name[20];
	int money;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> money;
	//객체 생성
	AccountArr[accNum++] = new Account(id, name, money);
	cout << " " << endl;
}
void Deposit() {
	int id;
	int money;
	cout << "[입   금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> money;
	//입금 처리
	for (int i = 0; i < accNum; i++) {
		if (AccountArr[i]->GetID() == id) {
			AccountArr[id]->Deposit(money);
			cout << "입금 완료: " << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void WithDraw() {
	int id;
	int money;
	cout << "[출   금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> money;
	//출금 처리
	for (int i = 0; i < accNum; i++) {
		if (AccountArr[i]->GetID() == id) {
			if (AccountArr[id]->Withdraw(money) == 0) {
				cout << "잔액부족" << endl << endl;
				return;
			}
			cout << "출금 완료: " << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}
void PrintAll() {
	for (int i = 0; i < accNum; i++) {
		cout << "계좌ID: " << AccountArr[i]->GetID() << endl;
		cout << "이름: " << AccountArr[i]->GetName() << endl;
		cout << "잔액: " << AccountArr[i]->GetMoney() << endl;
		cout << " " << endl;
	}
}

int main() {
	int insert_num;
	while (true) {
		ShowMenu();
		cout << "선택: ";
		cin >> insert_num;
		cout << " " << endl;
		switch (insert_num) {
		case 1: CreateAccount();
			break;
		case 2: Deposit();
			break;
		case 3: WithDraw();
			break;
		case 4: PrintAll();
			break;
		case 5:
			for (int i = 0; i < accNum; i++)
				delete AccountArr[i];
			return 0;
		default:
			cout << "다시 입력하세요.." << endl;
		}
	}
	return 0;
}