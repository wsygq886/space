#include "head.h"
#include "load.h"

void
trigger( Date *p )
{
	LOGFONT f;
	/*
	**正如触发器这个名字, 这个函数根据时间来启用其他函数
	*/
	if( p->month == 12 && p->day == 22 ){
		load_doc();
	}
	switch( p->month ){
		case 1:
			switch( p->day ){
				case 1:
					photo( 1275, 399, "unknown.jpg");
					play( "cough.mp3" );
					break;
				case 8:
					photo( 1275, 399, "ill.jpg");
					photo( 64, 246, "ill.jpg");
					play( "cough.mp3" );
					break;
				case 15:
					solidrectangle( 363, 752, 553, 775 );
					f = config_char( 24 );
					outtextxy( 363, 752, _T("新型冠状病毒肺炎") );
					photo( 64, 382, "illjpg");
					play( "cough.mp3" );
					break;
				case 22:
					photo( 1275, 240, "ill.jpg");
					play( "cough.mp3");
					break;
				case 29:
					play( "wuhan.wma" );
					photo( 1275, 544, "ill.jpg");
					Sleep( 25000 );
					break;
			}
			break;
		case 2:
			switch( p->day ){
				case 1:
					load_1();
					break;
				case 8:
					load_8();
					break;
				case 15:
					solidrectangle( 363, 752, 553, 775 );
					f = config_char( 24 );
					outtextxy( 363, 752, _T("COVID-19") );
					load_15();
					break;
				case 29:
					play( "cpc.mp3" );
					Sleep( 12000 );
					break;
				default:
					break;
			}
			break;
		case 3:
			switch( p->day ){
				case 8:
					play( "cube.mp3" );
					Sleep( 17000 );
					break;
				case 22:
					play( "who.mp3" );
					Sleep( 10000 );
					break;
				default:
					break;	
			}
			break;
		default:
			break;
	}
}