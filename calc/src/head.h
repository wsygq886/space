#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _node{
	double value;
	struct _node *next;
}Node;

typedef struct _list{
	Node *head;
	Node *end;
}List;

extern int eps;//不确定度表示精度

extern int error;//错误标志

char* read_unit(void);//读入测量单位

void read_data(List *q, int *size, double *average);//读入data.txt的数据

void checkSign(double data, int *check);//检查读入数据符号

int checkPoint(FILE *fp);//检查小数点位数

void checkSize(int size);//检查数据个数

void u_Decimal(double *u);//不确定度保留小数

void A(int size, List *q, double average, double *a);//计算A类不确定度

void B(double *b);//计算B类不确定度

void AB_total(double a, double b, double *u);//计算总不确定度

void EXIT(int size, char *c, List *q);//异常退出函数

void out(void);//异常退出函数(包含在EXIT中)

void DestroyList(List *q);//清除链表

void createNode(double *sum, int *size, List *q, double data);//当data.txt的数据通过检查时,创建一个链表来存储数据