#include "head.h"

void checkSign(double data, int *check)//����������ݷ���
{
	if(data<=0){
		int mode = 0;
		printf("data.txt���������з�����\n");
		do{
			printf("�Ƿ����?\n1:Yes\n2:No\n");
			scanf("%d", &mode);
			switch(mode){
				case 1:
					mode = 1;
					*check = 0;
					break;
				case 2:
					mode = 2;
					error = 1;
				default:printf("��Ч����!\n");
			}
		}while(mode==0);
	}
}