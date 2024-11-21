/*
* ���� �̸� : Account.h
* �ۼ��� �̸� : KNH
* ������Ʈ ���� : [2024,11,21] ���� ���� 0.7
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	int id;//���¹�ȣ
	char* name;//�̸�
	int money;//�ܾ�

public:
	Account(int pid, const char* pname, int pmoney);
	Account(const Account& ref);
	int GetID();
	char* GetName();
	int GetMoney();
	virtual void Deposit(int num);
	int Withdraw(int num);
	~Account();
};
#endif