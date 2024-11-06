#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	int age;
	char name[50];
public:
	Person(int myage, const char* myname) : age(myage) {
		strcpy(name, myname);
	}
	void WhatYourName() const {
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const {
		cout << "I'm " << age << " years old" << endl;
	}
};

class UnivStudent : public Person //Person클래스의 상속을 의미
{
private :
	char major[50];
public:
	UnivStudent(const char* myname, int myage, const char* mymajor) 
		: Person(myage, myname) 
	{
		strcpy(major, mymajor);
	}
	void WhoAreYou() const {
		WhatYourName();
		HowOldAreYou();
		//Person클래스를 상속했기 때문에 Person클래스의 멤버 함수를 호출할 수 있다.
		cout << "My major is " << major << endl << endl;
	}
};

int main(void) {
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
	ustd2.WhoAreYou();
	return 0;
}