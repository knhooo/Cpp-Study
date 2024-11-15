#include <iostream>
using namespace std;

class First {
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First {
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second {
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main() {
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj;
	//obj�� Second�� ����ϴ� Third ��ü�̹Ƿ�
	//Second�� �����ڷ� ������ �����ϴ�.
	sref.FirstFunc();
	sref.SecondFunc();
	//�����Ϸ��� �������� �ڷ����� ������ �Լ��� ȣ�� ���ɼ��� �Ǵ��ϹǷ�
	//FirstŬ������ ���ǵ� FirstFunc�Լ��� SecondŬ������ ���ǵ� SecondFunc �Լ���
	//ȣ���� ����������, Third Ŭ������ ���ǵ� ThirdFunc �Լ��� ȣ���� �Ұ����ϴ�.
	sref.SimpleFunc();
	//SimpleFunc�� �����Լ��̹Ƿ�, ThirdŬ������ ���ǵ� SimpleFunc �Լ��� ȣ��ȴ�.


	First& fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();
}