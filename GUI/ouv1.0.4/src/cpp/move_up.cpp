#include "head.h"

int
move_up( int step, Loc *xy )
{
	
	if( step > 0 ){
		setfillcolor( TRACK_BACK );
		solidcircle( 257, xy->y, 25 + DEL );
	}
	/*
	**step不为0, 圆圈要继续移动, 需要清除旧的圆圈; 如果为0则保留旧的圆圈
	*/

	/*
	**DEL是线宽, setlinestyle设置的, 清除的时候加上DEL才能连边框一起消掉
	*/
	while( step > 0 && xy->y > 225 ){
		setfillcolor( WHITE );
		solidcircle( 257, xy->y, 25 );
		Sleep(600);
		if( step > 1 ){
			setfillcolor( TRACK_BACK );
			solidcircle( 257, xy->y, 25 + DEL);
			xy->y -= 100;
		}
		step--;
	}

	return step;
}