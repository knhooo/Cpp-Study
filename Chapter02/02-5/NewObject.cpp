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
	//new �����ڸ� �̿��ؼ� �� ������ ���� �Ҵ�

	cout << "case 2: ";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);
	//malloc �Լ� ȣ���� ���ؼ� �� ������ ���� �Ҵ�
	cout << endl << "end of main" << endl;
	delete sp1;//new�� ����� �Ҵ翡 ���� �Ҹ�
	free(sp2);//malloc�� ����� �Ҵ翡 ���� �Ҹ�
	return 0;
	//new�� malloc�Լ��� ���� ��Ŀ��� ���̰� �ִ�.
}