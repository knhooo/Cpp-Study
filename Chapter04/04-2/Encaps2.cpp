#include <iostream>
using namespace std;

class SinivelCap { //콧물용 캡슐
public:
	void Take() const { cout << "콧물이 싸악 나아요." << endl; }
};

class SneezeCap {//재채기용 캡슐
public:
	void Take() const { cout << "재채기가 멎습니다." << endl; }
};

class SnuffleCap {//코막힘용 캡슐
public:
	void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};

class CONTAC600 {//캡슐화가 되어있는 코감기약 CONTAC600
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

class ColdPatient {//감기 환자

public:
	void TakeCOTAC600(const CONTAC600& cap) const { cap.Take();}
};//Encaps1.cpp의 ColdPatient 클래스보다 매우 간결해졌다.

int main()
{
	CONTAC600 cap;
	ColdPatient sufferer;
	//약의 복용 또한 Encaps1.cpp보다 간결해졌다.
	sufferer.TakeCOTAC600(cap);
	return 0;
}


