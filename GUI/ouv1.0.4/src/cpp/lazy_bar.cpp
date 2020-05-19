#include "head.h"

void
lazy_bar( int right )
{
	clearrectangle( 364, 824, 1009, 867 );	/*清除所有旧的怠惰值*/
	setfillcolor( RED );
	fillrectangle( 364, 824, right, 867);	/*绘制新的怠惰值*/
}