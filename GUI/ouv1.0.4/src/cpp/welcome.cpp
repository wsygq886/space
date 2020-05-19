#include "head.h"

void
Welcome( void )
{
	LOGFONT f;
	f = config_char( 50 );
	
	setlinestyle( PS_SOLID, 2 );

	rectangle( 520, 567, 920, 640 );
	outtextxy( 673, 580, _T("开始") );
	rectangle( 520, 690, 920, 763 );
	outtextxy( 673, 703, _T("退出") );
	f = config_char( 108 );
	outtextxy( 515, 209, _T("病毒往事") );
	f = config_char( 24 );
	outtextxy( 20, 850, _T("Develop by WWIandMC"));
	outtextxy( 1350, 850, _T("v1.0.4"));
}