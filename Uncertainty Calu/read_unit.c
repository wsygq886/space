#include "head.h"

char* read_unit(void)//���������λ

{
	char *c;
	int end;
	FILE *fp;
	fp = fopen("unit.txt", "rb");
	if(fp==NULL){
		printf("unit.txt��ʧ��!\n");
		out();
	}
	fseek(fp,0,SEEK_END);
	end = ftell(fp)+1;
	if(end==1){
		printf("unit.txtû������!\n");
		out();
	}
	rewind(fp);
	c = (char*)malloc(sizeof(char)*end);
	if(c==NULL){
		printf("read_unit�ڴ�����ʧ��!\n");
		out();
	}
	fgets(c,end,fp);
	fclose(fp);

	return c;
}