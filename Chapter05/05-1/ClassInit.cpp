#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num1;
    int num2;
public:
    SoSimple(int n1, int n2)
        : num1(n1), num2(n2)
    {
        //empty
    }
    //==================삽입된 디폴트 복사 생성자====================
    SoSimple(const SoSimple& copy)
        : num1(copy.num1), num2(copy.num2)
    {
        cout << "Called SoSimple(SoSimple &copy)" << endl;
    }
    //===============================================================
    void ShowSimpleData()
    {
        cout << num1 << endl;
        cout << num2 << endl;
    }
};

int main(void) {
    SoSimple sim1(15, 30);
    cout << "생성 및 초기화 직전" << endl;
    SoSimple sim2 = sim1;//SoSimple sim2(sim1);로 변환
    //SoSimple (sim1,sim2)의 생성자 필요
    //해당 유형의 생성자가 정의되어 있지 않으면 자동으로 생성자가 삽입된다.
    //=> 복사 생성자
    //다른 생성자의 정의와 상관 없이,복사 생성자가 정의되어있지 않으면
    //디폴트 복사 생성자가 자동으로 삽입된다.
    cout << "생성 및 초기화 직후" << endl;

    sim2.ShowSimpleData();
    return 0;
}