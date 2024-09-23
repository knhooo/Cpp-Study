#include <iostream>
using namespace std;

class SinivelCap { //�๰�� ĸ��
public:
	void Take() const { cout << "�๰�� �ξ� ���ƿ�." << endl; }
};

class SneezeCap {//��ä��� ĸ��
public:
	void Take() const { cout << "��ä�Ⱑ �ܽ��ϴ�." << endl; }
};

class SnuffleCap {//�ڸ����� ĸ��
public:
	void Take() const { cout << "�ڰ� �� �ո��ϴ�." << endl; }
};

class CONTAC600 {//ĸ��ȭ�� �Ǿ��ִ� �ڰ���� CONTAC600
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;

public:
	void Take() const {
		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient {//���� ȯ��

public:
	void TakeCOTAC600(const CONTAC600& cap) const { cap.Take();}
};//Encaps1.cpp�� ColdPatient Ŭ�������� �ſ� ����������.

int main()
{
	CONTAC600 cap;
	ColdPatient sufferer;
	//���� ���� ���� Encaps1.cpp���� ����������.
	sufferer.TakeCOTAC600(cap);
	return 0;
}


