#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

enum{LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2}
;
class Account {
private:
	int id;//계좌번호
	char* name;//이름
	int money;//잔액

public:
	Account(int pid, const char* pname, int pmoney)//생성자
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
	int GetID() {
		return id;
	}
	char* GetName() {
		return name;
	}
	int GetMoney() {
		return money;
	}
	virtual void Deposit(int num) {
		money += num;
	}
	int Withdraw(int num) {
		if (num > money) {
			return 0;
		}
		money -= num;
		return money;
	}
	
	~Account() {//소멸자
		delete[]name;
	}
};

//보통예금계좌
class NormalAccount : public Account
{
private:
	int interest;//이자율
public:
	NormalAccount(int pid, const char* pname, int pmoney, int pinterest)
		:Account(pid, pname, pmoney), interest(pinterest)
	{ }
	virtual void Deposit(int num) {
		Account::Deposit(num);
		Account::Deposit(num *(interest*0.01));//이자
	}
};
//신용신뢰계좌
class HighCreditAccount : public NormalAccount
{
private:
	int credit;
public:
	HighCreditAccount(int pid, const char* pname, int pmoney, int pinterest, int pcredit)
		:NormalAccount(pid, pname, pmoney, pinterest), credit(pcredit)
	{  }
	virtual void Deposit(int num) {
		NormalAccount::Deposit(num);
		Account::Deposit(num * (credit * 0.01));//추가 이자
	}
};

class AccountHandler 
{
private:
	Account* AccountArr[100];
	int accNum = 0;
public:
	AccountHandler();
	void ShowMenu(void) const;
	void CreateAccount(void);
	void Deposit(void);
	void Withdraw(void);
	void PrintAll(void) const;
	~AccountHandler();
protected:
	void CreateNormalAccount(void);
	void CreateCreditAccount(void);
};

AccountHandler::AccountHandler() : accNum(0)
{  }
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
		delete AccountArr[i];
}
void AccountHandler::ShowMenu(void) const {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입     금" << endl;
	cout << "3. 출     금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << " " << endl;
}

void AccountHandler::CreateAccount() {
	int selectNum;

	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cin >> selectNum;
	cout << endl;

	if (selectNum == 1)
		CreateNormalAccount();
	else
		CreateCreditAccount();
}

void AccountHandler::CreateNormalAccount() {
	int id;
	char name[20];
	int money;
	int interest; //이자율

	cout << "계좌ID: ";
	cin >> id;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> money;
	cout << "이자율: ";
	cin >> interest;
	AccountArr[accNum++] = new NormalAccount(id, name, money, interest);
	cout << " " << endl;
}

void AccountHandler::CreateCreditAccount() {
	int id;
	char name[20];
	int money;
	int interest; //이자율
	int credit; //신용등급

	cout << "계좌ID: ";
	cin >> id;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> money;
	cout << "이자율: ";
	cin >> interest;
	cout << "신용등급(1toA,2toB,3toC): ";
	cin >> credit;
	
	switch (credit) {
	case 1:
		AccountArr[accNum++] = new HighCreditAccount(id, name, money, interest, LEVEL_A);
		break;
	case 2:
		AccountArr[accNum++] = new HighCreditAccount(id, name, money, interest, LEVEL_B);
		break;
	case 3:
		AccountArr[accNum++] = new HighCreditAccount(id, name, money, interest, LEVEL_C);
		break;
	}
	cout << " " << endl;
}
void AccountHandler::Deposit() {
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
			AccountArr[i]->Deposit(money);
			cout << "입금 완료. " << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
	return;
}

void AccountHandler::Withdraw(void) {
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
			if (AccountArr[i]->Withdraw(money) == 0) {
				cout << "잔액부족" << endl << endl;
				return;
			}
			cout << "출금 완료. " << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
	return;
}
void AccountHandler::PrintAll() const{
	for (int i = 0; i < accNum; i++) {
		cout << "계좌ID: " << AccountArr[i]->GetID() << endl;
		cout << "이름: " << AccountArr[i]->GetName() << endl;
		cout << "잔액: " << AccountArr[i]->GetMoney() << endl;
		cout << " " << endl;
	}
}

int main() {
	int insert_num;

	AccountHandler handler;

	while (true) {
		handler.ShowMenu();
		cout << "선택: ";
		cin >> insert_num;
		cout << " " << endl;
		switch (insert_num) {
		case 1: handler.CreateAccount();
			break;
		case 2: handler.Deposit();
			break;
		case 3: handler.Withdraw();
			break;
		case 4: handler.PrintAll();
			break;
		case 5:
			return 0;
		default:
			cout << "다시 입력하세요.." << endl;
		}
	}
	return 0;
}