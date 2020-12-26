#include <iostream>
#include <string>
using namespace std;

struct Customer {
	string name;
	int ID;
};

struct Node {
	Customer data;
	Node* next;
};

struct LinkQueue {
	Node* head, * tail;
	int total;
};

struct Bst {
	Customer data;
	Bst* left, * right;
};

Bst* Find(int ID, Bst* t);
Bst* InsertBST(string* name, int ID, Bst* t);
Bst* FindMin(Bst* t);
Bst* DeleteBST(int ID, Bst* t);

void InitQueue(LinkQueue*& l);
void Push(LinkQueue*& l, Bst*& t, string* name, int ID);
bool Pop(LinkQueue*& l, Bst*& t);
bool InsertQueue(LinkQueue*& l, Bst*& t, int pos, string* name, int ID);
bool DeleteQueue(LinkQueue*& l, Bst*& t, int pos);
bool NameSearch(LinkQueue* l, const string& name);
void InOrderTraversal(Bst* t);
void IterQueue(LinkQueue* l);
void Storage(LinkQueue* l);

string info[] = {
	"1) �����Ŷ�����\n",
	"2) ���žͲ�\n",
	"3) ��ָ��λ�ò����µĿ�����Ϣ\n",
	"4) ɾ��ָ��λ�õĿ�����Ϣ\n",
	"5) �����������в���\n",
	"6) ���������Ž�������\n",
	"7) ����Ļ��������п��˵���Ϣ\n"
};

int main() {
	LinkQueue* l;
	InitQueue(l);
	Bst* t = NULL;
	int option, pos, ID;
	string name;
	while (true) {
		Storage(l);
		for (int i = 0; i < 7; i++)
			cout << info[i];
		cin >> option;
		switch (option) {
		case 1:
			int total;
			cout << "����������:";
			cin >> total;
			for (int i = 0; i < total; i++) {
				cout << "������������ѧ��:";
				cin >> name >> ID;
				Push(l, t, &name, ID);
			}
			break;
		case 2:
			Pop(l, t);
			break;
		case 3:
			cout << "������λ��:";
			cin >> pos;
			cout << "������������ѧ��:";
			cin >> name >> ID;
			if (!InsertQueue(l, t, pos, &name, ID))
				cout << "λ�ô���";
			break;
		case 4:
			cout << "������λ��:";
			cin >> pos;
			if (!DeleteQueue(l, t, pos))
				cout << "λ�ô���";
			break;
		case 5:
			cout << "����������";
			cin >> name;
			if (!NameSearch(l, name))
				cout << "������";
			break;
		case 6:
			if (t != NULL) {
				InOrderTraversal(t);
			}
			break;
		case 7:
			IterQueue(l);
			break;
		default:
			exit(0);
		}
		system("pause");
		system("cls");
	}
	return 0;
}

void InitQueue(LinkQueue*& l) {
	l = new LinkQueue;
	l->tail = l->head = new Node;
	l->head->next = NULL;
	l->total = 0;
}

Bst* Find(int ID, Bst* t) {
	if (!t) {
		return NULL;
	}
	if (ID > t->data.ID) {
		return Find(ID, t->right);
	}
	else if (ID < t->data.ID) {
		return Find(ID, t->left);
	}
	else {
		return t;
	}
}

Bst* InsertBST(string* name, int ID, Bst* t) {
	if (!t) {
		t = new Bst;
		t->data.ID = ID;
		t->data.name = *name;
		t->left = t->right = NULL;
	}
	else {
		if (ID < t->data.ID) {
			t->left = InsertBST(name, ID, t->left);
		}
		else if (ID > t->data.ID) {
			t->right = InsertBST(name, ID, t->right);
		}
	}
	return t;
}

Bst* FindMin(Bst* t) {
	if (!t) {
		return NULL; /*�յĶ���������������NULL*/
	}
	else if (!t->left) {
		return t;  /*�ҵ�����Ҷ��㲢����*/
	}
	else {
		return FindMin(t->left); /*�����֧��������*/
	}

}


Bst* DeleteBST(int ID, Bst* t) {
	Bst* temp;
	if (!t) {
		printf("Ҫɾ����Ԫ��δ�ҵ�");
	}
	else if (ID < t->data.ID) {
		t->left = DeleteBST(ID, t->left); /* �������ݹ�ɾ�� */
	}
	else if (ID > t->data.ID) {
		t->right = DeleteBST(ID, t->right); /* �������ݹ�ɾ�� */
	}
	else {	/*�ҵ�Ҫɾ���Ľ�� */
		if (t->left && t->right) { /*��ɾ����������������ӽ�� */
			temp = FindMin(t->right);
			/*��������������С��Ԫ�����ɾ�����*/
			t->data = temp->data;
			t->right = DeleteBST(t->data.ID, t->right);
			/*��ɾ��������������ɾ����СԪ��*/
		}
		else { /*��ɾ�������һ�������ӽ��*/
			temp = t;
			if (!t->left) /* ���Һ��ӻ����ӽ��*/
				t = t->right;
			else if (!t->right) /*�����ӻ����ӽ��*/
				t = t->left;
			delete temp;
		}
	}
	return t;
}


void Push(LinkQueue*& l, Bst*& t, string* name, int ID) {
	Node* ptr = new Node;
	ptr->data.ID = ID;
	ptr->data.name = *name;
	l->tail->next = ptr;
	l->tail = ptr;
	l->tail->next = NULL;
	t = InsertBST(name, ID, t);
	l->total++;
}

bool Pop(LinkQueue*& l, Bst*& t) {
	Node* ptr = l->head->next;
	if (l->head == l->tail) {
		return false;
	}
	l->head->next = l->head->next->next;
	t = DeleteBST(ptr->data.ID, t);
	delete ptr;
	l->total--;
	return true;
}

bool InsertQueue(LinkQueue*& l, Bst*& t, int pos, string* name, int ID) { //pos = 1��ʾ���ڶ�ͷ
	if (pos < 1 || pos > l->total + 1)
		return false;
	pos--;
	Node* ptr = l->head;
	while (pos--)
		ptr = ptr->next;
	Node* Iptr = new Node;
	Iptr->data.ID = ID;
	Iptr->data.name = *name;
	Iptr->next = ptr->next;
	ptr->next = Iptr;
	l->total++;
	t = InsertBST(name, ID, t);
	while (l->tail->next != NULL)
		l->tail = l->tail->next;
	l->tail->next = NULL;
	return true;
}

bool DeleteQueue(LinkQueue*& l, Bst*& t, int pos) {
	Node* pre = l->head, * cur = l->head->next;
	if (pos < 1 || pos > l->total)
		return false;
	pos--;
	while (cur != NULL && pos) {	//positionΪ�߼�λ��
		pre = pre->next;
		cur = cur->next;
		pos--;
	}
	pre->next = pre->next->next;
	if (cur == l->tail)
		l->tail = pre;
	t = DeleteBST(cur->data.ID, t);
	delete cur;
	l->total--;
	return true;
}

bool NameSearch(LinkQueue* l, const string& name) {
	Node* p = l->head->next;
	int pos = 0;
	while (p != NULL && p->data.name != name) {
		p = p->next;
		pos++;
	}
	if (p != NULL) {
		cout << pos + 1;
		return true;
	}
	return false;
}

void InOrderTraversal(Bst* t) {
	if (t == NULL)
		return;
	InOrderTraversal(t->left);
	cout << t->data.name << ' ' << t->data.ID << endl;
	InOrderTraversal(t->right);
}

void IterQueue(LinkQueue* l) {
	Node* p = l->head->next;
	while (p != NULL) {
		cout << p->data.name << ' ' << p->data.ID << endl;
		p = p->next;
	}
}

void Storage(LinkQueue* l) {
	printf("��ǰ������%d��\n", l->total);
	if (l->total != 0) {
		cout << "��һλ������:\t" << l->head->next->data.name << ' ' << l->head->next->data.ID << endl;
		cout << "���һλ������:\t" << l->tail->data.name << ' ' << l->tail->data.ID << endl;
	}
}