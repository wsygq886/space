#include "head.h"

void EXIT(int size, char *c, List *q)//�쳣�˳�����
{
	if(size!=0)DestroyList(q);
	free(c);
	out();
}
