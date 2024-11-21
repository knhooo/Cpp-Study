/*
* 파일 이름 : Account.cpp
* 작성자 이름 : KNH
* 업데이트 정보 : [2024,11,21] 파일 버전 0.7
*/

#include "BankingCommonDec1.h"
#include "Account.h"

Account::Account(int pid, const char* pname, int pmoney)//생성자
	:id(pid), money(pmoney)
{
	name = new char[strlen(pname) + 1];
	strcpy(name, pname);
}
Account::Account(const Account& ref)//복사 생성자
	:id(ref.id), money(ref.money)
{
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);
}
int Account::GetID() {
	return id;
}
char* Account::GetName() {
	return name;
}
int Account::GetMoney() {
	return money;
}
void Account:: Deposit(int num) {
	money += num;
}
int Account::Withdraw(int num) {
	if (num > money) {
		return 0;
	}
	money -= num;
	return money;
}

Account::~Account() {//소멸자
	delete[]name;
}
