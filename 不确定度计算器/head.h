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

extern int eps;//��ȷ���ȱ�ʾ����

extern int error;//�����־

char* read_unit(void);//���������λ

void read_data(List *q, int *size, double *average);//����data.txt������

void checkSign(double data, int *check);//���������ݷ���

int checkPoint(FILE *fp);//���С����λ��

void checkSize(int size);//������ݸ���

void u_Decimal(double *u);//��ȷ���ȱ���С��

void A(int size, List *q, double average, double *a);//����A�಻ȷ����

void B(double *b);//����B�಻ȷ����

void AB_total(double a, double b, double *u);//�����ܲ�ȷ����

void EXIT(int size, char *c, List *q);//�쳣�˳�����

void out(void);//�쳣�˳�����(������EXIT��)

void DestroyList(List *q);//�������

void createNode(double *sum, int *size, List *q, double data);//��data.txt������ͨ�����ʱ,����һ���������洢����