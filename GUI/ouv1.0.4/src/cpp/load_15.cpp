#include "head.h"

void
load_15( void )
{
	LOGFONT f;

	photo( 1260, 544, "amb.jpg");

	play( "emem.mp3" );

	f = config_char( 24 );
	outtextxy( 1218, 626, _T("���ҽ���ҽѧ��Ԯ"));
	
	Sleep( 8000 );
}