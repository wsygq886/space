#include "head.h"

void B(double *b)//����B�಻ȷ����
{
	int flag;
	int mode;
	double delta = 0;
	double C = 0;
	FILE *fp;
	fp = fopen("delta.txt", "rb");
	if(fp==NULL){
		printf("delta.txt��ʧ��\n");
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
				printf("delta.txtû������\n");
				error = 1;
				return;
			}
			break;
		}
	}
	do{
		printf("ѡ������ϵ��:\n");
		printf("1:3\n2:sqrt(3)\n3:sqrt(6)\n4:sqrt(2)\n");
		scanf("%d", &mode);
		switch(mode){
			case 1:C = 3;break;//��̬�ֲ�
			case 2:C = sqrt(3.0);break;//���ȷֲ�,һ�㰴���ȷֲ�����
			case 3:C = sqrt(6.0);break;//���Ƿֲ�
			case 4:C = sqrt(2.0);break;//�����ҷֲ�
			default:printf("��Ч����!\n");break;
		}
	}while(C==0);//C��ʼֵΪ0,��C��Ϊ0˵������modeֵ�Ǵ����,����ѭ��
	*b = delta/C;
	u_Decimal(b);
	if(error==1)return;
	printf("B�಻ȷ����=%.*lf\n", eps, *b);
}