/*
* 파일 이름 : AccountHandler.cpp
* 작성자 이름 : KNH
* 업데이트 정보 : [2024,11,21] 파일 버전 0.7
*/
#include "BankingCommonDec1.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

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
void AccountHandler::PrintAll() const {
	for (int i = 0; i < accNum; i++) {
		cout << "계좌ID: " << AccountArr[i]->GetID() << endl;
		cout << "이름: " << AccountArr[i]->GetName() << endl;
		cout << "잔액: " << AccountArr[i]->GetMoney() << endl;
		cout << " " << endl;
	}
}