#include<iostream>
using namespace std;

//Call-by-value & Call-by-reference

//값을 전달하면서 호출하게 되는 함수이므로 
//Call-by-value형태의 함수이다.
//이 경우 함수 외에 선언된 변수에는 접근이 불가능하다.
void SwapByValue(int num1, int num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
    //Call-by-value
}
//주소값을 이용하여 외부에 선언된 메모리 공간에
//접근할 수 있는 형태의 함수 호출이 이루어져있으므로
//Call-by-reference형태의 함수이다.
void SwapByRef(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    //Call-by-reference
}

/*
//예시 1
int num1 = 10, num2 = 20;
SwapByRef(&num1, &num2);
//num1과 num2의 주소 값을 전달했으므로 Call-by-refernce 형태이다.

//예시 2
int num1 = 10, num2 = 20;
int* p1 = &num1;
int* p2 = &num2;

SwapByRef(p1, p2);
//num1과 num2의 입장에서 SwapByRef함수는 Call-by-reference 이다.
//p1과 p2의 입장에서 SwapByRef함수는 Call-by-reference 인가?
//=> 아니다. 
//p1과 p2의 값(== num1과 num2의 주소값)을 전달하는것이지, p1과 p2의주소 값을 전달하는 것이 아니기 때문
*/

int main(void) {
    int val1 = 10;
    int val2 = 20;
    SwapByValue(val1, val2);
    cout << "val1 : " << val1 << endl;//10 출력
    cout << "val2 : " << val2 << endl;//20 출력
    //val1과 val2에 저장된 값이 서로 바뀌지 않았다.

    SwapByRef(&val1, &val2);
    cout << "val1: " << val1 << endl;//20 출력
    cout << "val2: " << val2 << endl;//10 출력
    //val1과 val2에 저장된 값이 서로 바뀌었다.
    return 0;
}
//------------------------------------------------------------------------------------------------------
//Call-by-address? Call-by-reference!

//C언어에서는 함수 외부에 선언된 메모리 공간에 접근하는 방식이 주소값을 전달하는 방법 뿐이었지만,
//C++에서는 주소값을 전달하는 방법과 참조자를 이용하는 방법 2가지가 있다.
//------------------------------------------------------------------------------------------------------
//참조자를 이용한 Call-by-reference

void SwapByRef2(int& ref1, int& ref2) {
    //ref1과 ref2는 선언과 동시에 초기화되지 않는 것처럼 보이지만
    //ref1과 ref2는 SwapByRef2가 호출되는 순간에 선언되고, SwapByRef2함수 인자로 받는 값으로 초기화가 이루어진다.
    //따라서 ref1과 ref2는 선언과 동시에 초기화되므로 참조자로서 문제가 되지 않는다.
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
    //Call-by-reference
}
//SwapByRef2함수를 빠져나간 뒤에는 참조자인 ref1,ref2만 소멸되고, val1,val2는 남아있는다.

int main(void) {
    int val1 = 10;
    int val2 = 20;
    SwapByRef2(val1, val2);
    //참조자가 함수의 인자로 선언되었으므로 val1과 val2의 값이 전달되는 것이 아니라,
    //val1과 va2를 참조하게 되는것이다...
    //va1과 ref1은 같은 메모리 공간에 붙은 이름이지만, val1은 main 스택에, ref1는 SwapByRef2()의 스택에 각각 존재한다..
    cout << "val1 ; " << val1 << endl;
    cout << "val2 : " << val2 << endl;
    return 0;
}
//이처럼 C++에서는 포인터를 사용하는 방법 뿐만 아니라 참조자를 통해서도 Call-by-reference형태가 가능하다.
//단점 : 함수의 호출문만 봐서는 Call-by-reference인지 Call-by-value인지 판단이 불가능하다. 매개변수가 어떻게 선언되었는지를 확인해야한다.
int num = 24;
HappyFunc(num);
cout << num << endl;

void HappyFunc(int& ref) {   }
//함수의 정의 형태와 함수의 호출 형태를 보아도 값의 변경 유무를 알 수 없다.

//------------------------------------------------------------------------------------------------------
//const 참조자
void HappyFunc(const int& ref) {   }
//함수 HappyFunc내에서 참조자 ref를 이용한 값의 변경은 하지 않겠다는 의미
//함수 내에서 참조자를 통한 값의 변경을 진행하지 않을 경우 참조자를 const로 선언해서,
//함수의 원형 선언만 봐도 값이 변형이 일어나지 않았음을 판단할 수 있다.

//------------------------------------------------------------------------------------------------------
//반환형이 참조형(Reference Type)이고, 반환도 참조로 받는 경우

//함수의 반환형에도 참조형이 선언될 수 있다.
int& RefRetFunOne(int& ref) {
    ref++;
    return ref;
}
//반환형이 참조자이므로 ref참조자의 데이터가 반환

int RefRetFunTwo(int& ref) {
    ref++;
    return ref;
}
//반환형이 int이므로 ref의 값이 반환 

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
//반환 과정
//int num1 = 1;
//int &ref = num1; //인자의 전달 과정에서 일어난 일
//int &num2 = ref; //함수의 반화노가 반환 값의 저장에서 일어난 일

//------------------------------------------------------------------------------------------------------

//잘못된 참조의 반환
int& RetuRefFunc(int n) {
    int num = 20;
    num += n;
    return num;
}
//위의 함수는 num을 참조의 형태로 반환하고 있다.
int& ref = RetuRefFunc(10);
//위의 형태로 함수를 호출하고 나면, 지역변수 num에 ref라는 또 하나의 이름이 붙게 된다.
//함수가 반환되고 나면 지역변수 num은 소멸이 된다...

//------------------------------------------------------------------------------------------------------

//const참조자의 또 다른 특징
const int num = 20;
int& ref = num; //<- 컴파일 에러 발생!
ref += 10;
cout << num << endl;
//const선언을 통해서 변수 num을 상수화했는데, 참조자 ref를 통해서 값을 변경할 수 있다면
//const선언의 의미가 없어진다..
//=>C++에서는 이를 허용하지 않는다.
const int num = 20;
const int& ref = num;
//위와 같이 선언이 되면 ref를 통한 값의 변경이 불가능하기 때문에 상수화에 대한 논리적인 문제점은 발생하지 않는다.
const int& ref = 50;
//const 참조자는 위와 같이 상수도 참조가 가능하다!

//------------------------------------------------------------------------------------------------------

//참조자가 상수를 참조할 수 있는 이유
int num = 20 + 30;
//위의 코드에서 20,30과 같은 프로그램상에서 표현되는 숫자를 '리터럴 상수(literal constant)'라고 한다.
//리터럴은 일시적으로 존재하는 값이며, 다음 행으로 넘어가면 존재하지 않는 상수이다.
const int& ref = 30;
//이는 30이 메모리 공간에 계속 남아있어야 성립되는 문장이다.
//C++에서는 const 참조자를 통해서 상수를 참조할 때, '임시변수'라는 것을 만든다.
//그리고 이 장소에 상수 30을 저장하고, 참조자가 이를 참조하도록 한다.
int Adder(const int& num1, const int& num2) {
    return num1 + num2;
}
//임시 변수의 생성을 통한 const 참조자의 상수 참조를 허용함으로써, 위의 함수는 다음과 같이 간단하게 호출할 수 있다.
cout << Adder(3, 4) << endl;