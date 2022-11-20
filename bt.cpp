#include<iostream>
using namespace std;
struct SinhVien {
	char HoTen[50];
	char GioiTinh[5];
	char MSSV[10];
	int Tuoi;
};
void Nhap(SinhVien& sv) {
	cout << "Nhap ho ten: ";
	cin >> sv.HoTen;
	fflush(stdin);
	cout << "Nhap Gioi Tinh: ";
	cin >> sv.GioiTinh;
	cout << "Nhap MSSV: ";
	cin >> sv.MSSV;
	cout << "Nhap Tuoi: ";
	cin >> sv.Tuoi;
}
void Xuat(SinhVien sv) {
	cout << "Ten: " << sv.HoTen << endl;
	cout << "Gioi Tinh: " << sv.GioiTinh << endl;
	cout << "MSSV: " << sv.MSSV << endl;
	cout << "Tuoi: " << sv.Tuoi << endl;
}

struct Node {
	SinhVien data;
	Node* next;
};
struct List {
	Node* head;
	Node* tail;
	List();
	Node* createNode(SinhVien x);
	void addFirst(SinhVien x);
	void addLast(SinhVien x);
	void insert(SinhVien x, int pos);
	void removeFirst();
	void removeLast();
	//void remove(int pos);
	void print();
	int Length();
};
List::List() {
	head = tail = NULL;
}
Node* List::createNode(SinhVien x) {
	Node* p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}
void List::addFirst(SinhVien x) {
	Node* p = createNode(x);
	if (head == NULL)
		head = tail = p;
	else {
		p->next = head;
		head = p;
	}
}
void List::print() {
	for (Node* i = head; i != NULL; i = i->next) {
		Xuat(i->data);
	}
}
void List::addLast(SinhVien x) {
	Node* p = createNode(x);
	if (head == NULL)
		head = tail = p;
	else {
		tail->next = p;
		tail = p;
	}
}
int List::Length()
{
		int dem = 0;
		for (Node* i = head; i != NULL; i->next)
		{
			dem++;
		}
		return dem;
}
void List::removeFirst()
{
	if (head == NULL)
		head = tail = NULL;
	else
	{
		head = head->next;
	}
}
void List::removeLast()
{
		int d = 0;
		Node* i;
		for (i = head; i != NULL; i - i->next)
		{
			d++;
			if (d == Length() - 1)
				break;
		}
		tail = i;
		i->next = NULL;
}

void List::insert(SinhVien x, int pos)
{
	Node* p = createNode(x);
	Node*ins = head;
    Node*Pre = NULL;
	if (head == NULL)
		head = tail = p;
	else
	{
		if (pos <0 || pos > Length())
			cout << "Node khong the chen";
		else 
		{
				
			int i = 0;
			while (ins!=NULL) {
				
				if (i=pos)
					break;
				Pre = ins;
				ins =ins->next;
				i++;
			}
	}
}
}
int main() {
	List l;
	SinhVien a,b;
	Nhap(a);
	Nhap(b);
	l.addFirst(a);
	l.insert(b,2);
	l.print();
};
