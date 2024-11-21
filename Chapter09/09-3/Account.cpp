/*
* ���� �̸� : Account.cpp
* �ۼ��� �̸� : KNH
* ������Ʈ ���� : [2024,11,21] ���� ���� 0.7
*/

#include "BankingCommonDec1.h"
#include "Account.h"

Account::Account(int pid, const char* pname, int pmoney)//������
	:id(pid), money(pmoney)
{
	name = new char[strlen(pname) + 1];
	strcpy(name, pname);
}
Account::Account(const Account& ref)//���� ������
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

Account::~Account() {//�Ҹ���
	delete[]name;
}
