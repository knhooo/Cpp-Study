#include <iostream>
using namespace std;

class SimpleClass {
private:
    int num1;
    int num2;
public:    
    SimpleClass(int n1 = 0, int n2 = 0) {
        num1 = n1;
        num2 = n2;
    }
    
    void ShowData() const {
        cout << num1 << ' ' << num2 << endl;
    }
};

int main()
{
    SimpleClass sc1();//함수의 원형 선언
    //sc1함수를 호출하여, 이 때 반환되는 객체의 값으로 mysc 객체를 초기화
    SimpleClass mysc = sc1();
    mysc.ShowData();
    return 0;
}

SimpleClass sc1() {
    SimpleClass sc(20, 30);
    return sc;
}