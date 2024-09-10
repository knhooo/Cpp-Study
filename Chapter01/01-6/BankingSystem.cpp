#include <iostream>

using std::string;

int num = 0;
int id[30];
string name[30];
int money[30];

void CreateAccount() { //계좌 개설

    std::cout << "계좌ID: ";
    std::cin >> id[num];
    std::cout << "이 름: ";
    std::cin >> name[num];
    std::cout << "입금액: ";
    std::cin >> money[num];

    num++;
}

void Deposit() {//입금
    int inserted_id;
    int deposit;
    int arr_num = 0;

    std::cout << "[입   금]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> inserted_id;
    std::cout << "입금액: ";
    std::cin >> deposit;
    std::cout << "입금 완료";
    std::cout << " " << std::endl;

    for (int i = 0; i < sizeof(id); i++) {
        if (id[i] == inserted_id) {
            arr_num = i;
        }
    }
    
    money[arr_num] += deposit;
}

void Withdraw() {//출금
    int inserted_id;
    int withdraw;
    int arr_num = 0;

    std::cout << "[출   금]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> inserted_id;
    std::cout << "출금액: ";
    std::cin >> withdraw;
    std::cout << "출금 완료";
    std::cout << " " << std::endl;

    for (int i = 0; i < sizeof(id); i++) {
        if (id[i] == inserted_id) {
            arr_num = i;
        }
    }

    money[arr_num] -= withdraw;
}

void PrintAll() {//계좌정보 전체 출력
    for (int i = 0; i < sizeof(id); i++) {
        if (id[i] == 0) break;
        std::cout << " " << std::endl;
        std::cout << "계좌ID: " << id[i] << std::endl;
        std::cout << "이 름: " << name[i] << std::endl;
        std::cout << "잔 액: " << money[i] << std::endl;
    }
}

int main()
{
    int insertNum;
    while (true) {
        std::cout << " " << std::endl;
        std::cout << "-----Menu-----" << std::endl;
        std::cout << "1. 계좌개설" << std::endl;
        std::cout << "2. 입 금" << std::endl;
        std::cout << "3. 출 금" << std::endl;
        std::cout << "4. 계좌정보 전체 출력" << std::endl;
        std::cout << "5. 프로그램 종료" << std::endl;
        std::cout << "선택: ";
        std::cin >> insertNum;
        std::cout << " " << std::endl;

        switch (insertNum)
        {
        case 1: CreateAccount();
            break;
        case 2: Deposit();
            break;
        case 3: Withdraw();
            break;
        case 4: PrintAll();
            break;
        case 5: return 0; //프로그램 종료
            break;
        default:
            break;
        }
    }
    return 0;
}
