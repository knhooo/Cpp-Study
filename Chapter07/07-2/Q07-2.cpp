//����2. ���� �� Ŭ������ ������ �����ڿ� �Ҹ��ڸ� �����غ���.
//�׸��� ���� Ȯ���� ���� main �Լ��� �����غ���.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo {
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* myname, int myage)
		: age(myage)
	{
		name = new char[strlen(myname + 1)];
		strcpy(name, myname);
	}
	void ShowMyFriendInfo() {
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~MyFriendInfo() {
		delete[] name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* myname, int myage, const char* myaddr, const char* myphone)
		:MyFriendInfo(myname, myage)
	{
		addr = new char[strlen(myaddr + 1)];
		strcpy(addr, myaddr);

		phone = new char[strlen(myphone + 1)];
		strcpy(phone, myphone);
	}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl;

	}
	~MyFriendDetailInfo() {
		delete[] addr;
		delete[] phone;
	}
};

int main() {
	MyFriendDetailInfo friend1("Kim",24, "����", "010-1234-5678");
	friend1.ShowMyFriendDetailInfo();
	return 0;
}