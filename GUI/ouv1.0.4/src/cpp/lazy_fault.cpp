#include "head.h"

void
lazy_fault( void )
{
	LOGFONT f;

	clear();

	f = config_char( 36 );
	outtextxy( 434, 390, _T("你的怠惰导致了疫情失控,游戏失败!") );

	Sleep( 3000 );
}