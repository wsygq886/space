#include "head.h"
#include "load.h"

void
time_change( Date *p )
{
	if( p->day == 29 ){
		if( p->month == 12 ){
			p->year++;
			p->month = 1;
		}else{
			p->month++;
		}
		p->day = 1;
	}else{
		p->day += 7;
	}
	/*
	**一个月只设置1, 8, 15, 22, 29; 步进为7
	*/
}