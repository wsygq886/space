#include "head.h"

void checkSize(int size)//������ݸ���
{
	if(size<5){
		if(size==0){
			printf("data.txtû������!\n");
		}else{
			printf("data.txt��������5��!\n");
		}
		error = 1;
	}
}