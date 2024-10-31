#define  _CRT_SECURE_NO_WARNINGS
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
        name = new char[len]; //new를 이용한 동적 할당
        strcpy(name, myname);
        age = myage;
    }
    void ShowPersonInfo() const {
        cout << "이름: " << name << endl;
        cout << "나이: " << name << endl;
    }
    ~Person() {
        delete[] name;//메모리 해제
        cout << "called destructor!" << endl;
    }
};

int main(void) {
    Person man1("Lee Dong woo", 29);
    Person man2 = man1;
    //디폴트 복사 생성자에 의한 멤버 대 멤버의 복사가 진행된다.
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}
