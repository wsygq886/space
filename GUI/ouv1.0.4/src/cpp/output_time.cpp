#include "head.h"

void
output_time( Date *p )
{
	struct {
		char ystr[5];
		char mstr[3];
		char dstr[3];
	}time;

	LOGFONT f;

	setfillcolor( INFO_COLOR );

	solidrectangle( 1150, 33, 1211, 65);		/*盖住年*/
	solidrectangle( 1252, 33, 1285, 65 );		/*盖住月*/
	solidrectangle( 1323, 33, 1362, 65 );		/*盖住日*/

	f = config_char( 32 );
	
	sprintf(time.ystr, "%d", p->year);
	sprintf(time.mstr, "%2d", p->month);
	sprintf(time.dstr, "%2d", p->day);

	outtextxy( 1150, 33, time.ystr);
	outtextxy( 1252, 33, time.mstr);
	outtextxy( 1323, 33, time.dstr);
}