#include "head.h"

void A(int size, List *q, double average, double *a)//����A�಻ȷ����
{
	double sum = 0;
	Node *p;
	for(p=q->head;p;p=p->next){
		sum += pow(p->value-average,2);
	}
	*a = sqrt(sum/size/(size-1));
	u_Decimal(a);
	if(error==1)return;
	printf("A�಻ȷ����=%.*lf\n", eps, *a);
}