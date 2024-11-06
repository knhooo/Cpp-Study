#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Account {
private:
	int id;//���¹�ȣ
	char* name;//�̸�
	int money;//�ܾ�

public:
	Account(int pid, char* pname, int pmoney)//������
	:id(pid),money(pmoney)
	{
		name = new char[strlen(pname) + 1];
		strcpy(name, pname);
	}
	int GetID() {
		return id;
	}
	char* GetName() {
		return name;
	}
	int GetMoney() {
		return money;
	}
	int Withdraw(int num) {
		if (num > money) {
			return 0;
		}
		money -= money;
		return money;
	}
	void Deposit(int num) {
		money += num;
	}
	~Account() {//�Ҹ���
		delete []name ;
	}
};

Account * AccountArr[100];
int accNum = 0;

void ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. ��     ��" << endl;
	cout << "3. ��     ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << " " << endl;
}

void CreateAccount() {
	int id;
	char name[20];
	int money;

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> money;
	//��ü ����
	AccountArr[accNum++] = new Account(id, name, money);
	cout << " " << endl;
}
void Deposit() {
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
			AccountArr[id]->Deposit(money);
			cout << "�Ա� �Ϸ�: " << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void WithDraw() {
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
			if (AccountArr[id]->Withdraw(money) == 0) {
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��� �Ϸ�: " << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}
void PrintAll() {
	for (int i = 0;i<accNum; i++) {
		cout << "����ID: "<< AccountArr[i]->GetID() << endl;
		cout << "�̸�: "<< AccountArr[i]->GetName() <<endl;
		cout << "�ܾ�: " << AccountArr[i]->GetMoney() << endl;
		cout << " " << endl;
	}
}

int main() {
	int insert_num;
	while (true) {
		ShowMenu();
		cout << "����: ";
		cin >> insert_num;
		cout << " " << endl;
		switch (insert_num) {
		case 1: CreateAccount();
			break;
		case 2: Deposit();
			break;
		case 3: WithDraw();
			break;
		case 4: PrintAll();
			break;
		case 5: 
			for (int i = 0; i < accNum; i++)
				delete AccountArr[i];
				return 0;
		default : 
			cout<<"�ٽ� �Է��ϼ���.."<<endl;
		}
	}
	return 0;
}