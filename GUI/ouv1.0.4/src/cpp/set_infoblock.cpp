#include "head.h"

void
set_infoblock( void )
{
	LOGFONT f;

	solidroundrect( 331, 720, 1042, 902, 10, 10 );	/*����ֵ������չʾ��*/

	f = config_char( 24 );
	outtextxy( 363, 752, _T("����ԭ�����") );

	f = config_char( 18 );
	outtextxy( 654, 752, _T("�ۼ�ȷ��") );
	outtextxy( 763, 752, _T("�ۼ�����") );
	outtextxy( 880, 752, _T("�ۼ�����") );
	outtextxy( 659, 872, _T("����ֵ") );

	/*������*/
	rectangle( 363, 823, 1010, 868 );
	clearrectangle( 364, 824, 1009, 867 );
	/*������*/
}