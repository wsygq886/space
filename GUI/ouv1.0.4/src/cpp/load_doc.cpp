#include "head.h"

void
load_doc( void )
{
	LOGFONT f;

	photo( 55, 542, "doc.jpg");

	f = config_char( 24 );
	outtextxy( 57, 626, _T("Œ‰∫∫“Ωª§"));
}