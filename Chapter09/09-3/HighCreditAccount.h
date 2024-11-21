/*
* ���� �̸� : HighCreditAccount.h
* �ۼ��� �̸� : KNH
* ������Ʈ ���� : [2024,11,21] ���� ���� 0.7
*/

#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__
#include "NormalAccount.h"

//�ſ�ŷڰ���
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
		Account::Deposit(num * (credit * 0.01));//�߰� ����
	}
};

#endif