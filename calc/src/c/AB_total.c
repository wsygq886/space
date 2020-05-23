#include "head.h"

void AB_total(double a, double b, double *u)//计算总不确定度
{
	*u = sqrt(a*a+b*b);
	printf("总不确定度=%.*lf\n", eps, *u);
}