#include "head.h"

void u_Decimal(double *u)//不确定度保留小数
{
	char *c,*ret;
	int cnt = 0;
	int i;
	int temp;
	temp = (int)*u;
	do{
		temp/=10;
		cnt++;
	}while(temp>0);
	c = (char*)malloc(sizeof(char)*cnt+8);
	if(c==NULL){
		printf("u_Decimal内存申请失败！\n");
		error = 1;
		return;
	}
	sprintf(c,"%lf", *u);
	ret = strchr(c,'.');
	for(i=1;i<strlen(ret);i++){
		if(ret[i]!='0')break;
	}
	if(ret[i]=='1' || ret[i]=='2'){
		*u = ((int)(ret[i]-'0'))*pow(10.0,-i)+((int)(c[i+1]-'0')+1)*pow(10.0,-i-1);
		eps = i+1;
	}else{
		*u = ((int)(ret[i]-'0')+1)*pow(10.0,-i);
		eps = i;
	}
	free(c);
}