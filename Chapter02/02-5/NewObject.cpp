#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple {
public:
	Simple() {
		cout << "I'm simple constructor!" << endl;
	}
};

int main(void) {
	cout << "case 1: ";
	Simple* sp1 = new Simple;
	//new 연산자를 이용해서 힙 영역에 변수 할당

	cout << "case 2: ";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);
	//malloc 함수 호출을 통해서 힙 영역에 변수 할당
	cout << endl << "end of main" << endl;
	delete sp1;//new를 사용한 할당에 대한 소멸
	free(sp2);//malloc을 사용한 할당에 대한 소멸
	return 0;
	//new와 malloc함수의 동작 방식에는 차이가 있다.
}