#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

int main() {
	char str1[50] = "��������";
	char str2[50] = "Ǯ���";

	cout << "���ڿ��� ���� : " << strlen(str1) << endl;
	cout << "strcat ��� : " << strcat(str1, str2) << endl;
	cout << "strcpy ��� : " << strcpy(str1, str2) << endl;
	cout << "strcmp ��� : " << strcmp(str1, str2) << endl;

	return 0;
}


