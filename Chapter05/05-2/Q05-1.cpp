#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int pos) {
		switch (pos) {
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
			break;
		}
	}
}

class NameCard {
private:
	char* name;
	char* comp_name;
	char* phone_num;
	int position;
public:
	NameCard(const char* name, const char* comp_name, const char* phone_num, int pos)
		:position(pos) 
	{
		this->name = new char[strlen(name) + 1];
		this->comp_name = new char[strlen(comp_name) + 1];
		this->phone_num = new char[strlen(phone_num) + 1];
		strcpy(this->name, name);
		strcpy(this->comp_name, comp_name);
		strcpy(this->phone_num, phone_num);
	}
	NameCard(const NameCard& ref) {
		name = new char[strlen(ref.name) + 1];
		comp_name = new char[strlen(ref.comp_name) + 1];
		phone_num = new char[strlen(ref.phone_num) + 1];
		strcpy(name, ref.name);
		strcpy(comp_name, ref.comp_name);
		strcpy(phone_num, ref.phone_num);
	}
	void ShowNameCardInfo() {
		cout << "이름: " << name << endl;
		cout << "회사: " << comp_name << endl;
		cout << "전화번호: " << phone_num << endl;
		cout << "직급: "; COMP_POS::ShowPositionInfo(position);
	}
	~NameCard() {
		delete[] name;
		delete[] comp_name;
		delete[] phone_num;
	}
};

int main(void) {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("HONG", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}