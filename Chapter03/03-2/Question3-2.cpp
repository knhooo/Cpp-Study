#include <iostream>
using namespace std;

//¹®Á¦ 1
class Calculator {
private :
	int addNum;
	int minNum;
	int mulNum;
	int divNum;
public :
	void Init() {
		addNum = 0;
		minNum = 0;
		mulNum = 0;
		divNum = 0;
	}

	void ShowOpCount() {
		cout << "µ¡¼À: " << addNum << " »¬¼À: " << minNum << " °ö¼À: " << mulNum << " ³ª´°¼À: " << divNum << endl;;
	}

	float Add(float num1,float num2) {
		addNum++;
		return num1 + num2;
	}
	float Min(float num1, float num2) {
		minNum++;
		return num1 - num2;
	}
	float Mul(float num1, float num2) {
		mulNum;
		return num1 * num2;
	}
	float Div(float num1, float num2) {
		divNum;
		return num1 / num2;
	}
};

int main(void) {
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}

//¹®Á¦2
class Printer {
private :
	string str;
public : 
	void SetString(string inputStr) {
		str = inputStr;
	}
	void ShowString() {
		cout << str << endl;
	}
};

int main(void) {
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}