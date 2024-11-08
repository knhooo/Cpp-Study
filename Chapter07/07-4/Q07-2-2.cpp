//����2 'å'�� �ǹ��ϴ� Book Ŭ������ '���� å'�� �ǹ��ϴ� Ebook Ŭ������ �����ϰ��� �Ѵ�.
//����å�� å�� �����̹Ƿ�, ������ ���� ���·� Ŭ������ ��� ���踦 �����ϰ��� �Ѵ�.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;//å�� ����
	char* isbn;//����ǥ�ص�����ȣ
	int price;//å�� ����
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
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
};

class EBook : public Book {
private :
	char* DRMKey; //���� ���� Ű
public:
	EBook(const char* ptitle, const char* pisbn, int pprice, const char* pdrmkey)
		:Book(ptitle, pisbn, pprice)
	{
		DRMKey = new char[strlen(pdrmkey) + 1];
		strcpy(DRMKey, pdrmkey);
	}
	void ShowEbookInfo() {
		ShowBookInfo();//BookŬ������ �Լ�
		cout << "����Ű: " << DRMKey << endl;
	}
};

int main(void) {
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEbookInfo();
	return 0;
}
