#include "head.h"

void
EXIT( const char *str )
{
	cleardevice();
	outtextxy( 350, 250, str );
	_getch();
	exit(1);
}