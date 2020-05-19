#include "head.h"

ACL_Sound
load_29( void )
{
	ACL_Sound pm;
	LOGFONT f;

	loadSound("iron.wma", &pm);
	playSound( pm, 1 );

	play("reinforcement.wma" );

	photo( 1260, 394, "amb.jpg");

	f = config_char( 24 );
	outtextxy( 1252, 475, _T("地方医疗队"));

	Sleep( 14000 );

	return pm;
}