#include "head.h"

void A(int size, List *q, double average, double *a)//计算A类不确定度
{
	double sum = 0;
	Node *p;
	for(p=q->head;p;p=p->next){
		sum += pow(p->value-average,2);
	}
	*a = sqrt(sum/size/(size-1));
	u_Decimal(a);
	if(error==1)return;
	printf("A类不确定度=%.*lf\n", eps, *a);
}