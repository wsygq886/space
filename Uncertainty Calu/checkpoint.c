#include "head.h"

int checkPoint(FILE *fp)//���С����λ��
{
	char c;
	int start,end;
	start = ftell(fp);
	fseek(fp,-(long)1,SEEK_CUR);
	while(1){
		fscanf(fp,"%c", &c);
		if(c=='.')break;
		fseek(fp,-(long)2,SEEK_CUR);
		end = ftell(fp);
	}
	fseek(fp,(long)start-end-1,SEEK_CUR);

	return start-end-1;
}