#include "head.h"

void AB_total(double a, double b, double *u)//�����ܲ�ȷ����
{
	*u = sqrt(a*a+b*b);
	printf("�ܲ�ȷ����=%.*lf\n", eps, *u);
}