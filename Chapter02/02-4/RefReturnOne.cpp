#include <iostream>
using namespace std;

//반환형이 참조이고 반환도 참조로 받는 경우
int& RefRetFunOne(int& ref) {
    ref++;
    return ref;
}

int main(void) {
    int num1 = 1;
    int& num2 = RefRetFunOne(num1);
    //num2의 자료형도 int&로 한다.
    //num2도 num1을 가리키는 참조자이다.

    num1++;
    num2++;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    return 0;
}