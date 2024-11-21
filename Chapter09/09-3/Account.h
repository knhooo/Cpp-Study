/*
* 파일 이름 : Account.h
* 작성자 이름 : KNH
* 업데이트 정보 : [2024,11,21] 파일 버전 0.7
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	int id;//계좌번호
	char* name;//이름
	int money;//잔액

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