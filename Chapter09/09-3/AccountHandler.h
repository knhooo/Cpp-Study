/*
* 파일 이름 : AccountHandler.h
* 작성자 이름 : KNH
* 업데이트 정보 : [2024,11,21] 파일 버전 0.7
*/

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__
#include "Account.h"

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
#endif