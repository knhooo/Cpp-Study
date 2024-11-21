/*
* 파일 이름 : HighCreditAccount.h
* 작성자 이름 : KNH
* 업데이트 정보 : [2024,11,21] 파일 버전 0.7
*/

#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__
#include "NormalAccount.h"

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

#endif