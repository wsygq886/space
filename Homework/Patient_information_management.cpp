#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
	string name;
	int age;
	string tel;
public:
	Patient* next;
	void InputData() {
		cin >> name >> age >> tel;
	}
	const string getName() {
		return name;
	}
	const string getTel() {
		return tel;
	}
	void printData() {
		cout << name << '\t' << age << '\t' << tel << endl;
	}
};

void initList(Patient*& p);		//��ʼ������
void createList(Patient* p);	//��������
void displayList(Patient* p);	//��˳��������������
void insert(Patient* p);		//��ָ��λ�ò�����
void delNode(Patient* p);		//ɾ��ָ��λ�õĽ��
void search(Patient* p);		//����ָ���Ľ��

int main() {
	cout << "Input Data" << endl;
	Patient* p;
	initList(p);
	createList(p);

	int option;
	while (true) {
		cout << "1. Insert" << endl << "2. Delete" << endl;
		cout << "3. Search" << endl << "-1. Exit" << endl;
		cin >> option;
		switch (option) {
		case 1:
			insert(p);
			displayList(p);
			break;
		case 2:
			delNode(p);
			displayList(p);
			break;
		case 3:
			search(p);
			break;
		case -1:
			goto out;
		}
	}
out: return 0;
}

void initList(Patient*& p) {
	p = new Patient;
	p->next = NULL;
}

void createList(Patient* p) {
	int num;
	cin >> num;
	Patient* q, * tail = p;
	for (int i = 0; i < num; i++) {		//β�巨����
		q = new Patient;
		q->InputData();
		tail->next = q;
		tail = q;
	}
	tail->next = NULL;
}

void insert(Patient* p) {
	int index;
	cout << "Insert: Enter the index" << endl;
	cin >> index;

	if (index < 0) { //indexΪ0, ��ʾ�嵽�����ĺ��� 
		cout << "Error: index cannot be negative." << endl;
		return;
	}

	int cnt = 0;
	while (cnt < index && p != NULL) {
		cnt++;
		p = p->next;
	}

	if (p == NULL) {	//NULLΪ���������־
		cout << "Error: index out of range." << endl;
		return;
	}
	else {
		cout << "Input data" << endl;
		Patient* n;
		n = new Patient;
		n->InputData();
		n->next = p->next;
		p->next = n;
	}
}

void displayList(Patient* p) {
	cout << endl << "Latest List" << endl;
	Patient* q = p->next;
	while (q != NULL) {
		q->printData();
		q = q->next;
	}
}

void delNode(Patient* p) {
	int index;
	cout << "Delete: Enter the index" << endl;
	cin >> index;
	if (index <= 0) {	//����ɾ�������, index����Ϊ0
		cout << "Error: index cannot be negative or zero." << endl;
		return;
	}
	int cnt = 1;
	Patient* cur, * pre;	//curָ��ǰ���, preָ��ǰ����ǰ�����
	cur = p->next;
	pre = p;
	while (cnt < index && cur != NULL) {
		cnt++;
		pre = cur;
		cur = cur->next;
	}

	if (cur == NULL) {
		cout << "Error: index out of range." << endl;
		return;
	}
	else {
		pre->next = cur->next;
		delete cur;
	}
}

void search(Patient* p) {
	cout << "Search: enter the telephone number" << endl;
	string key;
	cin >> key;
	while (p != NULL) {
		if (p->getTel() == key) {
			cout << "the name is " << p->getName() << endl;
			return;
		}
		p = p->next;
	}
	if (p == NULL) {
		cout << "Not Found" << endl;
	}
}