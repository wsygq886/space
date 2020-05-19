#include "head.h"
#include "output.h"

void
end_info( void )
{
	int i = 5;
	char str[82];

	FILE *fp;
	LOGFONT f;
	MOUSEMSG m;
	ACL_Sound pm;
	RECT r = { 0, 0, 1439, 899 };

	/*播放单曲循环*/
	loadSound( "end_info.wma", &pm );
	playSound( pm , 1 );
	/*播放单曲循环*/

	play( "wuhan1.mp3" );

	if( ( fp = fopen( "end_info.txt", "rb" ) ) == NULL ){
		EXIT( "end_info.txt not found" );
	}

	cleardevice();

	f = config_char( 36 );
	while( true ){
		m = GetMouseMsg();
		if( m.mkLButton == true ){
			final_score();
			Sleep( 500 );
			break;
		}
	}
	
	f = config_char( 30 );
	while( true ){
		m = GetMouseMsg();
		if( m.mkLButton == true ){
			if( fscanf( fp, "%s", str ) == EOF ){
				break;
			}
			cleardevice();
			drawtext( str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);	/*在屏幕正中间显示*/
			Sleep(500);
		}
		FlushMouseMsgBuffer();
	}
	cleardevice();
	f = config_char( 36 );
	outtextxy( 658, 390, _T("THE END"));
	_getch();
	stopSound( pm );
}