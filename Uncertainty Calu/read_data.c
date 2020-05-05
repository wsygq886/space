#include "head.h"

void read_data(List *q, int *size, double *average)//读入data.txt的数据
{
	int flag;			//fscanf的返回值
	int check = 1;		//控制数据检查
	int point;			//小数位数
	double data;
	double sum = 0;
	FILE *fp;
	fp = fopen("data.txt", "rb");
	if(fp==NULL){
		printf("data.txt打开失败\n");
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
				printf("%lf的小数位数与前一个测量值不同,请检查data.txt\n", data);
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