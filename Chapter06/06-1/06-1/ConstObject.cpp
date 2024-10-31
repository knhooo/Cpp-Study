#include <iostream>
using namespace std;

class SoSimple {
private:
    int num;
public:
    SoSimple(int n) : num(n)
    { }
    SoSimple& AddNum(int n) {
        num += n;
        return *this;
    }
    void ShowData() const {
        cout << "num: " << num << endl;
    }
};

int main(void) {
    const SoSimple obj(7);//const 객체 생성
    //obj.AddNum(20);//AddNum은 const함수가 아니기 때문에 호출 불가능
    obj.ShowData();
    //ShowData는 const함수이기 때문에 const 객체를 대상으로 호출 가능
    return 0;
}