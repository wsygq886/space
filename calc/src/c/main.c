#include "head.h"

int eps;
int error = 0;

int main(void)
{
	char *c;			//������λ
	int size = 0;		//�������ݸ���
	double average;		//ƽ����
	double a,b,u;		//a��A�಻ȷ����,b��B�಻ȷ����,u���ܲ�ȷ����
	List *q;
	c = read_unit();
	q = (List*)malloc(sizeof(List));
	if(q==NULL){
		printf("*q�ڴ�����ʧ��!");
		out();
	}
	read_data(q,&size,&average);
	if(error==0)checkSize(size);
	if(error==0)A(size,q,average,&a);
	if(error==0)B(&b);
	if(error==0)AB_total(a,b,&u);
	if(error==1)EXIT(size,c,q);
	printf("d = %.*lf��%.*lf%s P=(0.683)\n", eps, average, eps, u, c);
	DestroyList(q);
	free(c);

	system("pause");
	return 0;
}