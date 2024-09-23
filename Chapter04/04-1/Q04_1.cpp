#include <iostream>
using namespace std;

class FruitSeller {
private:
    //���� ����(������)
    int APPLE_PRICE; //����� ����
    int numOfApples; //�����ϰ� �ִ� ����� ��
    int myMoney; //�Ǹ� ����

public:
    void InitMembers(int price, int num, int money) {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }

    int SaleApples(int money) { //���� : ���� �Ǹ�
        if (money < 0) {
            cout << "��� ������ �� ����" << endl;
            return 0;
        }
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num; //�Ǹ��� ������ ���� ��ȯ
    }

    void ShowSalesResult() const {
        cout << "���� ���: " << numOfApples << endl;
        cout << "�Ǹ� ����: " << myMoney << endl;
    }
};

class FruitBuyer {
    int myMoney;  //�������� ������ ���� �� private:
    int numofApples; //private:

public:
    void InitMembers(int money) {
        myMoney = money;
        numofApples = 0;
    }
    bool BuyApples(FruitSeller& seller, int money) {
        if (money < 0) {
            cout << "��� ������ �� ����" << endl;
            return false;
        }
        numofApples += seller.SaleApples(money);
        myMoney -= money;
        return true;
    }
    void ShowBuyResult() const {
        cout << "���� �ܾ�: " << myMoney << endl;
        cout << "��� ����: " << numofApples << endl << endl;
    }
};

int main(void) {
    FruitSeller seller;//��ü ����
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;//��ü ����
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);//���� ����

    cout << "���� �Ǹ����� ��Ȳ" << endl;
    seller.ShowSalesResult();
    cout << "���� �������� ��Ȳ" << endl;
    buyer.ShowBuyResult();
    return 0;
}