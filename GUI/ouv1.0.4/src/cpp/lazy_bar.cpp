#include "head.h"

void
lazy_bar( int right )
{
	clearrectangle( 364, 824, 1009, 867 );	/*������оɵĵ���ֵ*/
	setfillcolor( RED );
	fillrectangle( 364, 824, right, 867);	/*�����µĵ���ֵ*/
}