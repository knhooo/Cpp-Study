//#include <iostream>
//namespace mystd { //cout과 endl을 직접 구현하기 위해 선언한 이름공간
//	using namespace std;//이 지역 내에서만 유효한 선언
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
//		fflush(stdout);//버퍼 비우기
//		return ostm;
//	}
//	ostream cout;
//}
//
//int main(void) {
//	using mystd::cout;//mystd내에 선언된 cout과 endl 사용
//	using mystd::endl;
//	cout << "Simple String"; //cout.operator<<("Simple String");
//	cout << endl;//cout.operator<<(endl);
//	cout << 3.14;//cout.operator<<(3.14);
//	cout << endl;//cout.operator<<(endl);
//	cout << 123;//cout.operator<<(123);
//	endl(cout);
//	return 0;
//}