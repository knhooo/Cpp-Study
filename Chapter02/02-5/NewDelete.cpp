#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

char* MakeStrAdr(int len) {
	//char* str = (char*)malloc(sizeof(char) * len);
	char* str = new char[len];//malloc대신 new를 사용
	return str;
}

int main(void) {
	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy!!");
	cout << str << endl;
	//free(str);
	delete[]str;//배열의 형태로 할당된 메모리 공간의 해제
	return 0;
}

