#include "head.h"

int
move_up( int step, Loc *xy )
{
	
	if( step > 0 ){
		setfillcolor( TRACK_BACK );
		solidcircle( 257, xy->y, 25 + DEL );
	}
	/*
	**step��Ϊ0, ԲȦҪ�����ƶ�, ��Ҫ����ɵ�ԲȦ; ���Ϊ0�����ɵ�ԲȦ
	*/

	/*
	**DEL���߿�, setlinestyle���õ�, �����ʱ�����DEL�������߿�һ������
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