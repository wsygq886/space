#include "head.h"

void
output_score_point( void )
{
	LOGFONT f;

	struct {
		char point[5];
		char score[5];
	}str;

	setfillcolor( INFO_COLOR );

	solidrectangle( 194, 760, 265, 796);		/*��ס�ж�������*/
	solidrectangle( 194, 836, 265, 872 );		/*��ס�÷�����*/

	f = config_char( 36 );

	sprintf( str.point, "%4d", point );
	sprintf( str.score, "%4d", score );

	outtextxy( 194, 764, str.point );
	outtextxy( 194, 840, str.score );
}