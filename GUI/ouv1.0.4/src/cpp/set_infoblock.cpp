#include "head.h"

void
set_infoblock( void )
{
	LOGFONT f;

	solidroundrect( 331, 720, 1042, 902, 10, 10 );	/*怠惰值和数据展示框*/

	f = config_char( 24 );
	outtextxy( 363, 752, _T("不明原因肺炎") );

	f = config_char( 18 );
	outtextxy( 654, 752, _T("累计确诊") );
	outtextxy( 763, 752, _T("累计治愈") );
	outtextxy( 880, 752, _T("累计死亡") );
	outtextxy( 659, 872, _T("怠惰值") );

	/*进度条*/
	rectangle( 363, 823, 1010, 868 );
	clearrectangle( 364, 824, 1009, 867 );
	/*进度条*/
}