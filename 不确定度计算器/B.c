#include "head.h"

void B(double *b)//计算B类不确定度
{
	int flag;
	int mode;
	double delta = 0;
	double C = 0;
	FILE *fp;
	fp = fopen("delta.txt", "rb");
	if(fp==NULL){
		printf("delta.txt打开失败\n");
		error = 1;
		return;
	}
	while(1){
		flag = fscanf(fp,"%lf", &delta);
		if(flag==0){
			fseek(fp,(long)1,1);
			continue;
		}else if(flag==EOF){
			if(delta==0){
				printf("delta.txt没有数据\n");
				error = 1;
				return;
			}
			break;
		}
	}
	do{
		printf("选择置信系数:\n");
		printf("1:3\n2:sqrt(3)\n3:sqrt(6)\n4:sqrt(2)\n");
		scanf("%d", &mode);
		switch(mode){
			case 1:C = 3;break;//正态分布
			case 2:C = sqrt(3.0);break;//均匀分布,一般按均匀分布处理
			case 3:C = sqrt(6.0);break;//三角分布
			case 4:C = sqrt(2.0);break;//反正弦分布
			default:printf("无效输入!\n");break;
		}
	}while(C==0);//C初始值为0,若C仍为0说明输入mode值是错误的,继续循环
	*b = delta/C;
	u_Decimal(b);
	if(error==1)return;
	printf("B类不确定度=%.*lf\n", eps, *b);
}