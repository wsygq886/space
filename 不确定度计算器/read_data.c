#include "head.h"

void read_data(List *q, int *size, double *average)//����data.txt������
{
	int flag;			//fscanf�ķ���ֵ
	int check = 1;		//�������ݼ��
	int point;			//С��λ��
	double data;
	double sum = 0;
	FILE *fp;
	fp = fopen("data.txt", "rb");
	if(fp==NULL){
		printf("data.txt��ʧ��\n");
		error = 1;
		return;
	}
	while(1){
		flag = fscanf(fp,"%lf", &data);
		if(flag==EOF){
			break;
		}
		else if(flag==0){
			fseek(fp,1,SEEK_CUR);
			continue;
		}
		if(check)checkSign(data,&check);
		if(*size==0){
			point = checkPoint(fp);
		}else{
			if(point!=checkPoint(fp)){
				printf("%lf��С��λ����ǰһ������ֵ��ͬ,����data.txt\n", data);
				error = 1;
				return;
			}
		}
		createNode(&sum,size,q,data);
		if(error==1)return;
	}
	*average = sum/(*size);
	fclose(fp);
}