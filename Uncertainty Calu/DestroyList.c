#include "head.h"

void DestroyList(List *q)//Çå³ýÁ´±í
{
	Node *p,*tp;
	for(p=q->head;p;p=tp){
		tp = p->next;
		free(p);
	}
	free(q);
}