#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		printf("0~100사이의 난수 %d: %d\n",i,rand()%100);
	}
}