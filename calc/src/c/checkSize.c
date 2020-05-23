#include "head.h"

void checkSize(int size)//检查数据个数
{
	if(size<5){
		if(size==0){
			printf("data.txt没有数据!\n");
		}else{
			printf("data.txt数据少于5个!\n");
		}
		error = 1;
	}
}