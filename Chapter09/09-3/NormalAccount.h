/*
* 파일 이름 : NormalAccount.h
* 작성자 이름 : KNH
* 업데이트 정보 : [2024,11,21] 파일 버전 0.7
*/

#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__
#include "Account.h"

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
		Account::Deposit(num * (interest * 0.01));//이자
	}
};
#endif