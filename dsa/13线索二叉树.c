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
    *	��������
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

tbtnode* pre;       //ȫ�ֱ���

void
Thread(tbtnode* p)
{
    if (p != NULL) {
        Thread(p->lchild);		//��������ȱ���������
        if (p->lchild == NULL) {
            p->ltag = 1;        //�����������
            p->lchild = pre;    //ָ��ǰ�ڵ��ǰ���ڵ�
        }
        else {
            p->ltag = 0;        //���ú���ָ����
        }
        if (pre->rchild == NULL) {
            pre->rtag = 1;      
            pre->rchild = p;    //ǰһ���ڵ�ָ��ǰ�ڵ㣬����ָ��ָ���̽ڵ�
        }
        else {
            pre->rtag = 0;
        }
        pre = p;                //pre��p��ǰ�ƶ�
        Thread(p->rchild);		//������������������
    }		
}

tbtnode*
createThread(tbtnode* t)
{
    tbtnode* root;
    root = (tbtnode*)malloc(sizeof(tbtnode));
    root->ltag = 0;
    root->rtag = 1;
    root->rchild = t;   //ͷ�����Һ���ָ�뿪ʼʱָ�����ĸ��ڵ�

    if (t == NULL) {
        root->lchild = root;
    }
    else {
        root->lchild = t;
        pre = root;
        Thread(t);
        pre->rchild = root;
        /*
        * �뿪Thread()ʱpΪ��ָ��, preָ��������������е����һ���ڵ�
        * �����һ���ڵ���Һ���ָ��ָ���̽ڵ�root
        */
        pre->rtag = 1;
        root->rchild = pre;
    }
    return root;

}

void
InOrderTraverse_Thr(tbtnode* t)
{
    tbtnode* p = t->lchild;     //pָ����ڵ�

    while (p != t) {
        while (p->ltag == 0) {  //�����������ҵ���ʼ�ڵ�
            p = p->lchild;
        }
        printf("%c", p->data);  //��ӡ��ʼ�ڵ�
        while (p->rtag == 1 && p->rchild != t) {    //��������һ·������ȥ
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;  //pָ����һ������
    }
}