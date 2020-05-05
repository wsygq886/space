#include "head.h"

void checkSign(double data, int *check)//检查输入数据符号
{
	if(data<=0){
		int mode = 0;
		printf("data.txt的数据中有非正数\n");
		do{
			printf("是否继续?\n1:Yes\n2:No\n");
			scanf("%d", &mode);
			switch(mode){
				case 1:
					mode = 1;
					*check = 0;
					break;
				case 2:
					mode = 2;
					error = 1;
				default:printf("无效输入!\n");
			}
		}while(mode==0);
	}
}