//#include <iostream>
//namespace mystd { //cout�� endl�� ���� �����ϱ� ���� ������ �̸�����
//	using namespace std;//�� ���� �������� ��ȿ�� ����
//
//	class ostream {
//	public:
//		//<<dustkswk dhqjfheld
//		void operator<<(const char* str) {
//			printf("%s", str);
//		}
//		void operator<<(char str) {
//			printf("%c", str);
//		}
//		void operator<<(int num) {
//			printf("%d", num);
//		}
//		void operator<<(double e) {
//			printf("%g", e);
//		}
//		void operator<< (ostream& (*fp)(ostream& ostream)) {
//			fp(*this);
//		}
//	};
//	ostream& endl(ostream& ostm) {
//		ostm << '\n';
//		fflush(stdout);//���� ����
//		return ostm;
//	}
//	ostream cout;
//}
//
//int main(void) {
//	using mystd::cout;//mystd���� ����� cout�� endl ���
//	using mystd::endl;
//	cout << "Simple String"; //cout.operator<<("Simple String");
//	cout << endl;//cout.operator<<(endl);
//	cout << 3.14;//cout.operator<<(3.14);
//	cout << endl;//cout.operator<<(endl);
//	cout << 123;//cout.operator<<(123);
//	endl(cout);
//	return 0;
//}