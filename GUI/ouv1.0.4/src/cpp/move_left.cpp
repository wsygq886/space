#include "head.h"

int
move_left( int step, Loc *xy )
{	
	if( step > 0 ){
		setfillcolor( TRACK_BACK );
		solidcircle( xy->x, 625, 25 + DEL);
	}
	/*
	**step��Ϊ0, ԲȦҪ�����ƶ�, ��Ҫ����ɵ�ԲȦ; ���Ϊ0�����ɵ�ԲȦ
	*/

	/*
	**DEL���߿�, setlinestyle���õ�, �����ʱ�����DEL�������߿�һ������
	*/
	while ( step > 0 && xy->x > 257 ){
		setfillcolor( WHITE );
		solidcircle( xy->x, 625, 25 );
		Sleep(600);
		if( step > 1 ){
			setfillcolor( TRACK_BACK );
			solidcircle( xy->x, 625, 25 + DEL );
			xy->x -= 100;
		}
		step--;
	}

	return step;
}
