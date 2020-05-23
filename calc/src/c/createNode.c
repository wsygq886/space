#include "head.h"

void createNode(double *sum, int *size, List *q, double data)//当data.txt的数据通过检查时,创建一个链表来存储数据
{
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	if(p==NULL){
			printf("createList申请内存失败！");
			error = 1;
			return;
	}
	*size += 1;
	p->value = data;
	*sum += p->value;
	if(*size==1){
		p->next = NULL;
		q->head = p;
		q->end = p;
	}else{
		p->next = NULL;
		q->end->next = p;
		q->end = p;
	}
}