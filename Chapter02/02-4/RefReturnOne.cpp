#include <iostream>
using namespace std;

//��ȯ���� �����̰� ��ȯ�� ������ �޴� ���
int& RefRetFunOne(int& ref) {
    ref++;
    return ref;
}

int main(void) {
    int num1 = 1;
    int& num2 = RefRetFunOne(num1);
    //num2�� �ڷ����� int&�� �Ѵ�.
    //num2�� num1�� ����Ű�� �������̴�.

    num1++;
    num2++;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    return 0;
}