//문제2 '책'을 의미하는 Book 클래스와 '전자 책'을 의미하는 Ebook 클래스를 정의하고자 한다.
//전자책도 책의 일종이므로, 다음과 같은 형태로 클래스의 상속 관계를 구성하고자 한다.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;//책의 제목
	char* isbn;//국제표준도서번호
	int price;//책의 정가
public:
	Book(const char* ptitle, const char* pisbn, int pprice)
		: price(pprice)
	{
		title = new char[strlen(ptitle) + 1];
		strcpy(title, ptitle);
		isbn = new char[strlen(pisbn) + 1];
		strcpy(isbn, pisbn);
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
};

class EBook : public Book {
private :
	char* DRMKey; //보안 관련 키
public:
	EBook(const char* ptitle, const char* pisbn, int pprice, const char* pdrmkey)
		:Book(ptitle, pisbn, pprice)
	{
		DRMKey = new char[strlen(pdrmkey) + 1];
		strcpy(DRMKey, pdrmkey);
	}
	void ShowEbookInfo() {
		ShowBookInfo();//Book클래스의 함수
		cout << "인증키: " << DRMKey << endl;
	}
};

int main(void) {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEbookInfo();
	return 0;
}
