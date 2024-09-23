#include <iostream>
using namespace std;

class FruitSeller {
private:
    //상태 정보(데이터)
    int APPLE_PRICE; //사과의 가격
    int numOfApples; //보유하고 있는 사과의 수
    int myMoney; //판매 수익

public:
    void InitMembers(int price, int num, int money) {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }

    int SaleApples(int money) { //행위 : 과일 판매
        if (money < 0) {
            cout << "벗어난 범위의 값 전달" << endl;
            return 0;
        }
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num; //판매한 과일의 수를 반환
    }

    void ShowSalesResult() const {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl;
    }
};

class FruitBuyer {
    int myMoney;  //접근제어 지시자 생략 시 private:
    int numofApples; //private:

public:
    void InitMembers(int money) {
        myMoney = money;
        numofApples = 0;
    }
    bool BuyApples(FruitSeller& seller, int money) {
        if (money < 0) {
            cout << "벗어난 범위의 값 전달" << endl;
            return false;
        }
        numofApples += seller.SaleApples(money);
        myMoney -= money;
        return true;
    }
    void ShowBuyResult() const {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numofApples << endl << endl;
    }
};

int main(void) {
    FruitSeller seller;//객체 생성
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;//객체 생성
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);//과일 구매

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();
    return 0;
}