#include "head.h"

void DestroyList(List *q)//�������
{
	Node *p,*tp;
	for(p=q->head;p;p=tp){
		tp = p->next;
		free(p);
	}
	free(q);
}