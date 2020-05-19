#include "head.h"

void
load_8( void )
{
	LOGFONT f;

	photo( 1267, 230, "hos.jpg");

	play( "thunder.wma" );

	f = config_char( 24 );
	outtextxy( 1276, 321, _T("À×ÉñÉ½"));

	Sleep( 10000 );
}