#include "head.h"
#include "move.h"
#include <time.h>

void
move( Date *date, Loc *xy )
{
	int step;
	time_t t;

	srand( (unsigned)time( &t ) );
	step = rand() % 6 + 1;
	point += step;
	step++;
	/*����1�Ļ�ȦȦ����Ļ�ϸ�ֻ�ƶ�point-1��*/

	while( step != 0 ){
		if( xy->y == 225 ){
			step = move_right( step, xy );
		}
		if( xy->x == 1157 ){
			step = move_down( step, xy );
		}
		if( xy->y == 625 ){
			step = move_left( step, xy );
		}
		if( xy->x == 257 ){
			step = move_up( step, xy );
		}
	}
}
