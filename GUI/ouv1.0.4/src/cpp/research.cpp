#include "head.h"
#include "output.h"

void
research( FILE *fp, FILE *fp0 )
{
	LOGFONT f;
	setfillcolor( INFO_COLOR );

	char str[100];
	
	if( fscanf( fp, "%s", str ) != EOF ){
		solidrectangle( 176, 39, 1085, 58 );
		f = config_char( 20 );
		outtextxy( 176, 39, str );
		fscanf( fp0, "%s", str );
	}
	score++;
	point--;
	output_score_point();
	Sleep(100);
}