#include "head.h"

void
Welcome( void )
{
	LOGFONT f;
	f = config_char( 50 );
	
	setlinestyle( PS_SOLID, 2 );

	rectangle( 520, 567, 920, 640 );
	outtextxy( 673, 580, _T("��ʼ") );
	rectangle( 520, 690, 920, 763 );
	outtextxy( 673, 703, _T("�˳�") );
	f = config_char( 108 );
	outtextxy( 515, 209, _T("��������") );
	f = config_char( 24 );
	outtextxy( 20, 850, _T("Develop by WWIandMC"));
	outtextxy( 1350, 850, _T("v1.0.4"));
}