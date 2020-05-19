#include "head.h"

void
final_score( void )
{
	char str[5];
	LOGFONT f;
	
	f = config_char( 36 );

	outtextxy( 614, 390, _T("你的得分是") );
	sprintf( str, "%d", score );
	outtextxy( 793, 390, str );
}