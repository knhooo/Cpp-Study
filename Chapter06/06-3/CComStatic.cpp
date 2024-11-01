#include <iostream>
using namespace std;

void Counter() {
	static int cnt;
	//전역변수와 마찬가지로 초기화하지 않으면 0으로 초기화된다.
	//딱 한번만 실행이 된다.
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main(void) {
	for (int i = 0; i < 10; i++)
		Counter();
	return 0;
}