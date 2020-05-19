#include "head.h"

void
photo( int x, int y, const char *name )
{
	IMAGE i;
	loadimage( &i, name );
	putimage( x, y , &i );
}