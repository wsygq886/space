#include "head.h"

void
lazy_fault( void )
{
	LOGFONT f;

	clear();

	f = config_char( 36 );
	outtextxy( 434, 390, _T("��ĵ��赼��������ʧ��,��Ϸʧ��!") );

	Sleep( 3000 );
}