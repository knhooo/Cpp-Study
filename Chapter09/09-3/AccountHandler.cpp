/*
* ���� �̸� : AccountHandler.cpp
* �ۼ��� �̸� : KNH
* ������Ʈ ���� : [2024,11,21] ���� ���� 0.7
*/
#include "BankingCommonDec1.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler() : accNum(0)
{  }
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
		delete AccountArr[i];
}
void AccountHandler::ShowMenu(void) const {
	cout << "-----Menu-----" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. ��     ��" << endl;
	cout << "3. ��     ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << " " << endl;
}

void AccountHandler::CreateAccount() {
	int selectNum;

	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cin >> selectNum;
	cout << endl;

	if (selectNum == 1)
		CreateNormalAccount();
	else
		CreateCreditAccount();
}

void AccountHandler::CreateNormalAccount() {
	int id;
	char name[20];
	int money;
	int interest; //������

	cout << "����ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> money;
	cout << "������: ";
	cin >> interest;
	AccountArr[accNum++] = new NormalAccount(id, name, money, interest);
	cout << " " << endl;
}

void AccountHandler::CreateCreditAccount() {
	int id;
	char name[20];
	int money;
	int interest; //������
	int credit; //�ſ���

	cout << "����ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> money;
	cout << "������: ";
	cin >> interest;
	cout << "�ſ���(1toA,2toB,3toC): ";
	cin >> credit;

	switch (credit) {
	case 1:
		AccountArr[accNum++] = new HighCreditAccount(id, name, money, interest, LEVEL_A);
		break;
	case 2:
		AccountArr[accNum++] = new HighCreditAccount(id, name, money, interest, LEVEL_B);
		break;
	case 3:
		AccountArr[accNum++] = new HighCreditAccount(id, name, money, interest, LEVEL_C);
		break;
	}
	cout << " " << endl;
}
void AccountHandler::Deposit() {
	int id;
	int money;
	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> money;
	//�Ա� ó��
	for (int i = 0; i < accNum; i++) {
		if (AccountArr[i]->GetID() == id) {
			AccountArr[i]->Deposit(money);
			cout << "�Ա� �Ϸ�. " << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
	return;
}

void AccountHandler::Withdraw(void) {
	int id;
	int money;
	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> money;
	//��� ó��
	for (int i = 0; i < accNum; i++) {
		if (AccountArr[i]->GetID() == id) {
			if (AccountArr[i]->Withdraw(money) == 0) {
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��� �Ϸ�. " << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
	return;
}
void AccountHandler::PrintAll() const {
	for (int i = 0; i < accNum; i++) {
		cout << "����ID: " << AccountArr[i]->GetID() << endl;
		cout << "�̸�: " << AccountArr[i]->GetName() << endl;
		cout << "�ܾ�: " << AccountArr[i]->GetMoney() << endl;
		cout << " " << endl;
	}
}