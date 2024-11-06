//문제2. 다음 두 클래스에 적절한 생성자와 소멸자를 정의해보자.
//그리고 이의 확인을 위한 main 함수를 정의해보자.
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
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
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
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl;

	}
	~MyFriendDetailInfo() {
		delete[] addr;
		delete[] phone;
	}
};

int main() {
	MyFriendDetailInfo friend1("Kim",24, "서울", "010-1234-5678");
	friend1.ShowMyFriendDetailInfo();
	return 0;
}