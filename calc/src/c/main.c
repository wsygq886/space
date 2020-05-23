#include "head.h"

int eps;
int error = 0;

int main(void)
{
	char *c;			//测量单位
	int size = 0;		//读入数据个数
	double average;		//平均数
	double a,b,u;		//a是A类不确定度,b是B类不确定度,u是总不确定度
	List *q;
	c = read_unit();
	q = (List*)malloc(sizeof(List));
	if(q==NULL){
		printf("*q内存申请失败!");
		out();
	}
	read_data(q,&size,&average);
	if(error==0)checkSize(size);
	if(error==0)A(size,q,average,&a);
	if(error==0)B(&b);
	if(error==0)AB_total(a,b,&u);
	if(error==1)EXIT(size,c,q);
	printf("d = %.*lf±%.*lf%s P=(0.683)\n", eps, average, eps, u, c);
	DestroyList(q);
	free(c);

	system("pause");
	return 0;
}