#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0

#define MAXSIZE 100

typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
}SqList;

void   initList(SqList** l);						//初始化一个空的线性表
void   createList(SqList* l, ElemType a[], int n);	//建立一个线性表
void   destroyList(SqList* l);						//销毁线性表
Status listEmpty(SqList* l);						//判断线性表是否为空
int    listLength(SqList* l);						//取得线性表的长度
void   dispList(SqList* l);							//打印线性表
int    getElem(SqList* l, int i, ElemType* e);		//取得线性表中指定位置的元素
int    locateElem(SqList* l, ElemType e);		    //取得线性表中指定元素的位置
Status listInsert(SqList* l, int i, ElemType e);	//在线性表的指定位置插入新元素
Status listDelete(SqList* l, int i, ElemType* e);	//在线性表的指定位置删除元素

int main() {
    SqList* l;
    ElemType a[] = { 9,12,3,54,75 };
    ElemType e;
    initList(&l);
    createList(l, a, sizeof(a) / sizeof(ElemType));
    dispList(l);
    getElem(l, 2, &e);
    printf("\n线性表的第2个位置是%d\n", e);
    printf("\n54位于线性表的第%d个位置\n", locateElem(l, 54));
    printf("\n在线性表的第2个位置插入60\n");
    listInsert(l, 2, 60);
    dispList(l);
    printf("\n删除线性表第3个位置的元素\n");
    listDelete(l, 3, &e);
    printf("被删除的元素是%d\n", e);
    dispList(l);
    destroyList(l);
    return 0;
}

void initList(SqList** l) {	//初始化线性表：构造一个空的线性表l
    (*l) = (SqList*)malloc(sizeof(SqList));
    (*l)->length = 0;
}

void createList(SqList* l, ElemType a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        l->data[i] = a[i];
    }
    l->length = n;
}

void destroyList(SqList* l) {
    free(l);
}

Status listEmpty(SqList* l) {
    return (l->length == 0);
}

int listlength(SqList* l) {
    return (l->length);
}


void dispList(SqList* l) {
    int i;
    if (listEmpty(l)) {
        printf("线性表为空\n");
        return;
    }
    for (i = 0; i < l->length; i++) {
        printf("%d ", l->data[i]);
    }
    printf("\n");
}

Status getElem(SqList* l, int i, ElemType* e) {
    if (i < 1 || i > l->length) {
        return FALSE;
    }
    *e = l->data[i - 1];
    /*
    **物理位序 = 逻辑位序 + 1
    */
    return TRUE;
}

int locateElem(SqList* l, ElemType e) {
    int i = 0;
    while (i < l->length&& l->data[i] != e) {
        i++;
    }
    if (i >= l->length) {
        return 0;
    }
    else {
        return i + 1;
        /*
        ** 返回的是逻辑位序
        */
    }
}

Status listInsert(SqList* l, int i, ElemType e) {
    int j;
    if (i < 1 || i > l->length + 1) {		/*判断给出的下标是否合法*/
        return FALSE;
    }
    i--;
    for (j = l->length; j > i; j--) {
        l->data[j] = l->data[j - 1];
    }
    l->data[i] = e;
    l->length++;
    return TRUE;
}

Status listDelete(SqList* l, int i, ElemType* e)
{
    int j;
    if (i < 1 || i > l->length) {	/*判断给出的下标是否合法*/
        return FALSE;
    }
    i--;
    *e = l->data[i];
    for (j = i; j < l->length - 1; j++) {
        l->data[j] = l->data[j + 1];
    }
    l->length--;
    return TRUE;
}