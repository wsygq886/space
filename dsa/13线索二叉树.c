#include <stdio.h>
#include <stdlib.h>

typedef struct _tbtnode {
	char data;
	int ltag, rtag;
	struct _tbtnode* lchild, * rchild;
}tbtnode;

void
createTree(tbtnode** t);

void
Thread(tbtnode* p);

tbtnode*
createThread(tbtnode* t);

void
InOrderTraverse_Thr(tbtnode* t);

int main()
{
	tbtnode* t;
	createTree(&t);
	/*
	*	输入样例
	*	ABD#G###CE##F##
	*/
	t = createThread(t);
	InOrderTraverse_Thr(t);

	return 0;
}

void
createTree(tbtnode** t)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#') {
		*t = NULL;
	}
	else {
		*t = (tbtnode*)malloc(sizeof(tbtnode));
		(*t)->data = ch;
		createTree(&((*t)->lchild));
		createTree(&((*t)->rchild));
	}
}

tbtnode* pre;

void
Thread(tbtnode* p)
{
	if (p != NULL) {
		Thread(p->lchild);		//中序遍历先遍历左子树
		if (p->lchild == NULL) {
			p->ltag = 1;
			p->lchild = pre;
		}
		else {
			p->ltag = 0;
		}
		if (pre->rchild == NULL) {
			pre->rtag = 1;
			pre->rchild = p;
		}
		else {
			pre->rtag = 0;
		}
		pre = p;
		Thread(p->rchild);		//中序遍历后遍历右子树
	}		
}

tbtnode*
createThread(tbtnode* t)
{
	tbtnode* root;
	root = (tbtnode*)malloc(sizeof(tbtnode));
	root->ltag = 0;
	root->rtag = 1;
	root->rchild = t;

	if (t == NULL) {
		root->lchild = root;
	}
	else {
		root->lchild = t;
		pre = root;
		Thread(t);
		pre->rchild = root;
		pre->rtag = 1;
		root->rchild = pre;
	}
	return root;

}

void
InOrderTraverse_Thr(tbtnode* t)
{
	tbtnode* p = t->lchild;
	while (p != t) {
		while (p->ltag == 0) {
			p = p->lchild;
		}
		printf("%c", p->data);
		while (p->rtag == 1 && p->rchild != t) {
			p = p->rchild;
			printf("%c", p->data);
		}
		p = p->rchild;
	}
}