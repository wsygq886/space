#include "head.h"

void createNode(double *sum, int *size, List *q, double data)//��data.txt������ͨ�����ʱ,����һ���������洢����
{
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	if(p==NULL){
			printf("createList�����ڴ�ʧ�ܣ�");
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