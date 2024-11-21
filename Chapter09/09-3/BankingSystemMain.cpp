/*
* ����Ʈ���� ���� : Banking System Ver 0.7
* 
* ���� �̸� : BankingSystemMain.h
* �ۼ��� �̸� : KNH
* ������Ʈ ���� : [2024,11,21] ���� ���� 0.7
*/

#include "BankingCommonDec1.h"
#include "AccountHandler.h"

int main() {
	int insert_num;

	AccountHandler handler;

	while (true) {
		handler.ShowMenu();
		cout << "����: ";
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
			cout << "�ٽ� �Է��ϼ���.." << endl;
		}
	}
	return 0;
}