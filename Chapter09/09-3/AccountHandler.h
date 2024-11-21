/*
* ���� �̸� : AccountHandler.h
* �ۼ��� �̸� : KNH
* ������Ʈ ���� : [2024,11,21] ���� ���� 0.7
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