#include <iostream>

void MyFunc(void) { //1번
    std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c) { //2번
    std::cout << "MyFunc(char c) called" << std::endl;
}

void MyFunc(int a, int b) { //3번
    std::cout << "MyFunc(int a, int b) called" << std::endl;
}

int main()
{
    MyFunc(); //1번
    MyFunc('A'); //2번
    MyFunc(12, 13); //3번
    return 0;
}

