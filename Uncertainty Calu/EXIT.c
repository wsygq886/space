#include "head.h"

void EXIT(int size, char *c, List *q)//Òì³£ÍË³öº¯Êý
{
	if(size!=0)DestroyList(q);
	free(c);
	out();
}
