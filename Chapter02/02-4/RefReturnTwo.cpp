#include <iostream>
using namespace std;

//반환형은 참조이되 반환은 변수로 받는 경우
int& RefRetFunTwo(int& ref) {
    ref++;
    return ref;
}

int main(void) {
    int num1 = 1;
    int num2 = RefRetFunTwo(num1);
    //참조형으로 반환이 되지만, 참조자가 아닌 일반변수를 선언해서
    //반환 값을 저장할 수도 있다.
    //num1과 num2는 아무 관계도 없는 별개의 변수이다.

    num1+=1;
    num2+=100;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    return 0;
}