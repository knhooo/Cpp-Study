/*
* 소프트웨어 버전 : Banking System Ver 0.7
* 
* 파일 이름 : BankingSystemMain.h
* 작성자 이름 : KNH
* 업데이트 정보 : [2024,11,21] 파일 버전 0.7
*/

#include "BankingCommonDec1.h"
#include "AccountHandler.h"

int main() {
	int insert_num;

	AccountHandler handler;

	while (true) {
		handler.ShowMenu();
		cout << "선택: ";
		cin >> insert_num;
		cout << " " << endl;
		switch (insert_num) {
		case 1: handler.CreateAccount();
			break;
		case 2: handler.Deposit();
			break;
		case 3: handler.Withdraw();
			break;
		case 4: handler.PrintAll();
			break;
		case 5:
			return 0;
		default:
			cout << "다시 입력하세요.." << endl;
		}
	}
	return 0;
}