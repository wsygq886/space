#include "head.h"

char* read_unit(void)//读入测量单位

{
	char *c;
	int end;
	FILE *fp;
	fp = fopen("unit.txt", "rb");
	if(fp==NULL){
		printf("unit.txt打开失败!\n");
		out();
	}
	fseek(fp,0,SEEK_END);
	end = ftell(fp)+1;
	if(end==1){
		printf("unit.txt没有数据!\n");
		out();
	}
	rewind(fp);
	c = (char*)malloc(sizeof(char)*end);
	if(c==NULL){
		printf("read_unit内存申请失败!\n");
		out();
	}
	fgets(c,end,fp);
	fclose(fp);

	return c;
}