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

tbtnode* pre;       //全局变量

void
Thread(tbtnode* p)
{
    if (p != NULL) {
        Thread(p->lchild);		//中序遍历先遍历左子树
        if (p->lchild == NULL) {
            p->ltag = 1;        //设置线索标记
            p->lchild = pre;    //指向当前节点的前趋节点
        }
        else {
            p->ltag = 0;        //设置孩子指针标记
        }
        if (pre->rchild == NULL) {
            pre->rtag = 1;      
            pre->rchild = p;    //前一个节点指向当前节点，即让指针指向后继节点
        }
        else {
            pre->rtag = 0;
        }
        pre = p;                //pre和p向前移动
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
    root->rchild = t;   //头结点的右孩子指针开始时指向树的根节点

    if (t == NULL) {
        root->lchild = root;
    }
    else {
        root->lchild = t;
        pre = root;
        Thread(t);
        pre->rchild = root;
        /*
        * 离开Thread()时p为空指针, pre指向了中序遍历序列的最后一个节点
        * 让最后一个节点的右孩子指针指向后继节点root
        */
        pre->rtag = 1;
        root->rchild = pre;
    }
    return root;

}

void
InOrderTraverse_Thr(tbtnode* t)
{
    tbtnode* p = t->lchild;     //p指向根节点

    while (p != t) {
        while (p->ltag == 0) {  //遍历左子树找到开始节点
            p = p->lchild;
        }
        printf("%c", p->data);  //打印开始节点
        while (p->rtag == 1 && p->rchild != t) {    //沿着线索一路访问下去
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;  //p指向下一棵子树
    }
}