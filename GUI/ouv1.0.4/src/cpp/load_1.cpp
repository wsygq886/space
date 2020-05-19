#include "head.h"

void
load_1( void )
{
	LOGFONT f;

	photo( 56, 230, "hos.jpg");
	photo( 55, 371, "pla.jpg");

	play( "pla.mp3");

	f = config_char( 24 );
	outtextxy( 64, 321, _T("火神山"));
	outtextxy( 45, 477, _T("人民解放军"));

	Sleep( 37000 );
}