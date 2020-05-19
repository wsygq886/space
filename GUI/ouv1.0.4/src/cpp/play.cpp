#include "head.h"

void
play( const char *name )
{
	ACL_Sound p;
	loadSound( name, &p );
	playSound( p, 0 );
}