/*���� 1 
* Chapter07������ ���� HasComposite.cpp�� ���ؼ� ������ �� Ŭ������ �����Ͽ���.
* �̿� Police Ŭ������ ������� ���� ���簡 �̷������� ���� �����ڿ� ���� �����ڸ� 
* ���ÿ� �����ϰ� ���� Ȯ���� ���� main�Լ��� ������ �����غ���.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shut()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff)
		:handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(const Police& ref)
		:handcuffs(ref.handcuffs) {
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));//Gun�� ���� ������ ȣ��
		else
			pistol = NULL;
	}
	Police& operator=(const Police& ref) {
		if (pistol != NULL)
			delete pistol;
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else pistol = NULL;

		handcuffs = ref.handcuffs;
		pistor = ref.pistol;
		return *this;
	}
	void PutHandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shut() {
		if (pistol == NULL)
			cout << "Hut BBang!" << endl;
		else
			pistol->Shut();
	}
	~Police() {
		if (pistol != NULL)
			delete pistol;
	}
};

int main(void) {
	Police pman1(5, 3);
	Police pman2 = pman1;//���� ������ ȣ��
	pman2.PutHandcuff();
	pman2.Shut();

	Police pman3(2, 4); 
	pman3 = pman1;//���� �������� ȣ��
	pman3.PutHandcuff();
	pman3.Shut();
	
	return 0;
}

/*���� 2
* Chapter 07�� ���� 07-2�� �� ��° ���������� ������ �� Ŭ���� ���Ǹ� �䱸�Ͽ���.
* �� �� ������ �� Ŭ������ ������� BookŬ������, EBookŬ������ ���� ���簡 ������ �ǵ���
* ���� �����ڿ� ���� �����ڸ� �����ϰ�, ���� Ȯ���� ���� main�Լ��� ������ �����غ���.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* ptitle, const char* pisbn, int pprice)
		: price(pprice)
	{
		title = new char[strlen(ptitle) + 1];
		strcpy(title, ptitle);
		isbn = new char[strlen(pisbn) + 1];
		strcpy(isbn, pisbn);
	}
	Book(const Book& ref) : price(ref.price)
	{
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}
	Book& operator=(const Book& ref) {
		delete[] title;
		delete[] isbn;

		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
		price = ref.price;

		return *this;
	}
	void ShowBookInfo() {
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
	~Book() {
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book {
private:
	char* DRMKey; 
public:
	EBook(const char* ptitle, const char* pisbn, int pprice, const char* pdrmkey)
		:Book(ptitle, pisbn, pprice)
	{
		DRMKey = new char[strlen(pdrmkey) + 1];
		strcpy(DRMKey, pdrmkey);
	}
	EBook(const EBook& ref) : Book(ref)
	{
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	EBook& operator=(const Ebook& ref) {
		Book::operator=(ref);
		delete[]DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);

		return *this;
	}
	void ShowEbookInfo() {
		ShowBookInfo();
		cout << "DRMKey: " << DRMKey << endl;
	}
	~EBook() {
		delete[] DRMKey;
	}
};

int main(void) {
	EBook ebook1("�������� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1;//���� �������� ȣ��
	ebook2.ShowEbookInfo();
	cout << endl;

	EBook ebook3("dddd", "ddd", 0, "dddd");
	ebook3 = ebook2;//���� �������� ȣ��
	ebook3.ShowEbookInfo();

	ebook.ShowEbookInfo();
	return 0;
}