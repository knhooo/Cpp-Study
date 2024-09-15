#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
//C의 표준에 정의된 함수들 조차 이름공간 std 안에 선언이 되어 있어서 이 문장이 삽입되어야 한다.

int main(void) {
	char str1[] = "Result";
	char str2[30];

	strcpy(str2, str1);
	printf("%s: %f \n", str1, sin(0.14));
	printf("%s: %f \n", str2, abs(-1.25));

	return 0;
}
