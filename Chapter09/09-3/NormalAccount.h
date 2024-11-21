/*
* ���� �̸� : NormalAccount.h
* �ۼ��� �̸� : KNH
* ������Ʈ ���� : [2024,11,21] ���� ���� 0.7
*/

#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__
#include "Account.h"

class NormalAccount : public Account
{
private:
	int interest;//������
public:
	NormalAccount(int pid, const char* pname, int pmoney, int pinterest)
		:Account(pid, pname, pmoney), interest(pinterest)
	{ }
	virtual void Deposit(int num) {
		Account::Deposit(num);
		Account::Deposit(num * (interest * 0.01));//����
	}
};
#endif