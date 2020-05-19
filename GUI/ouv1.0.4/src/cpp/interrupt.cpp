#include "head.h"
#include "output.h"

void
interrupt( void )
{
	clear();
	final_score();
	_getch();
}