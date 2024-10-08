#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	char* name;
	int age;
public:
	Person(char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	//생성자
	Person() {
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	//초기화
	void SetPersonInfo(char* myname, int myage) {
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const {
		cout << "이름: " << name << ", ";
		cout << "나이: " << age << endl;
	}
	~Person() {
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void) {
	Person* parr[3];//포인터 배열 선언
	//객체의 주소 값 3개를 저장할 수 있다.
	char namestr[100];
	char* strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++) {
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;
		parr[i] = new Person(namestr, age);
		//객체를 생성하여 객체의 주소값을 배열에 저장
	}
	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();
	delete parr[0];
	delete parr[1];
	delete parr[2];
	return 0;
}