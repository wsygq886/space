#include "head.h"

void
case_report( FILE *fp )
{
	LOGFONT f;
	char str[6];

	setfillcolor( INFO_COLOR );
	solidrectangle( 650, 780, 934, 808 );	/*��ס���оɵĲ�������*/

	f = config_char( 24 );
	for( int start = 662; start < 1001; start += 113 ){
		/*662������������ߵ����ֵ�������Ϊ��׼*/
		fscanf( fp, "%s", str );
		outtextxy( start, 780, str );
	}
}