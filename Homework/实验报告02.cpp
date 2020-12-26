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
	"1) 新增排队人数\n",
	"2) 安排就餐\n",
	"3) 在指定位置插入新的客人信息\n",
	"4) 删除指定位置的客人信息\n",
	"5) 根据姓名进行查找\n",
	"6) 按饭卡卡号进行排序\n",
	"7) 在屏幕上输出所有客人的信息\n"
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
			cout << "请输入人数:";
			cin >> total;
			for (int i = 0; i < total; i++) {
				cout << "请输入姓名和学号:";
				cin >> name >> ID;
				Push(l, t, &name, ID);
			}
			break;
		case 2:
			Pop(l, t);
			break;
		case 3:
			cout << "请输入位置:";
			cin >> pos;
			cout << "请输入姓名和学号:";
			cin >> name >> ID;
			if (!InsertQueue(l, t, pos, &name, ID))
				cout << "位置错误";
			break;
		case 4:
			cout << "请输入位置:";
			cin >> pos;
			if (!DeleteQueue(l, t, pos))
				cout << "位置错误";
			break;
		case 5:
			cout << "请输入姓名";
			cin >> name;
			if (!NameSearch(l, name))
				cout << "不存在";
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
		return NULL; /*空的二叉搜索树，返回NULL*/
	}
	else if (!t->left) {
		return t;  /*找到最左叶结点并返回*/
	}
	else {
		return FindMin(t->left); /*沿左分支继续查找*/
	}

}


Bst* DeleteBST(int ID, Bst* t) {
	Bst* temp;
	if (!t) {
		printf("要删除的元素未找到");
	}
	else if (ID < t->data.ID) {
		t->left = DeleteBST(ID, t->left); /* 左子树递归删除 */
	}
	else if (ID > t->data.ID) {
		t->right = DeleteBST(ID, t->right); /* 右子树递归删除 */
	}
	else {	/*找到要删除的结点 */
		if (t->left && t->right) { /*被删除结点有左右两个子结点 */
			temp = FindMin(t->right);
			/*在右子树中找最小的元素填充删除结点*/
			t->data = temp->data;
			t->right = DeleteBST(t->data.ID, t->right);
			/*在删除结点的右子树中删除最小元素*/
		}
		else { /*被删除结点有一个或无子结点*/
			temp = t;
			if (!t->left) /* 有右孩子或无子结点*/
				t = t->right;
			else if (!t->right) /*有左孩子或无子结点*/
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

bool InsertQueue(LinkQueue*& l, Bst*& t, int pos, string* name, int ID) { //pos = 1表示插在队头
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
	while (cur != NULL && pos) {	//position为逻辑位序
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
	printf("当前队伍有%d人\n", l->total);
	if (l->total != 0) {
		cout << "下一位客人是:\t" << l->head->next->data.name << ' ' << l->head->next->data.ID << endl;
		cout << "最后一位客人是:\t" << l->tail->data.name << ' ' << l->tail->data.ID << endl;
	}
}