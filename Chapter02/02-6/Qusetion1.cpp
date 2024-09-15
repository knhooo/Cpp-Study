#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

int main() {
	char str1[50] = "연습문제";
	char str2[50] = "풀어보기";

	cout << "문자열의 길이 : " << strlen(str1) << endl;
	cout << "strcat 결과 : " << strcat(str1, str2) << endl;
	cout << "strcpy 결과 : " << strcpy(str1, str2) << endl;
	cout << "strcmp 결과 : " << strcmp(str1, str2) << endl;

	return 0;
}


