//#include <iostream>
//
//namespace mystd {
//	using namespace std;
//
//	class ostream {
//	//cout ��ü�� �������� ��ȯ�ϴ� ���·� Ȯ��
//	public:
//		ostream& operator<< (char* str)
//		{
//			printf("%s", str);
//			return *this;
//		}
//		ostream& operator<< (char str)
//		{
//			printf("%c", str);
//			return *this;
//		}
//		ostream& operator<<(int num) {
//			printf("%d", num);
//			return *this;
//		}
//		ostream& operator<<(double e) {
//			printf("%g", e);
//			return *this;
//		}
//		ostream& operator<<(ostream& (*fp)(ostream& ostm)) {
//			return fp(*this);
//		}
//	};
//
//	//endl�Լ��� ���ڷ� ���޵� ��ü�� �������� ��ȯ�ϹǷ�,
//	//��ȯ�� ���� �� ��ȯ�ϴ� ���·� �����ڸ� �����ε�
//	ostream& endl(ostream& ostm) {
//		ostm << '\n';
//		fflush(stdout);
//		return ostm;
//	}
//	ostream cout;
//}
//
//int main(void) {
//	using mystd::cout;
//	using mystd::endl;
//	cout << 3.14 << endl << 123 << endl;
//	return 0;
//}
