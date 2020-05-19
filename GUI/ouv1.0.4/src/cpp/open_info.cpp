#include "head.h"

void
open_info( void )
{
	char		str[45];
	FILE		*fp;
	LOGFONT		f;
	MOUSEMSG	m;

	setbkcolor( RGB( 215, 193, 167 ) );		/*设置设备背景色*/
	setbkmode( INFO_COLOR );				/*设置字体背景色*/
	setfillcolor( INFO_COLOR );				/*设置图形填充色*/
	settextcolor( BLACK );					/*设置字体颜色*/
	cleardevice();

	if( ( fp = fopen( "open_info.txt", "rb") ) == NULL ){
		EXIT( "open_info.txt not found" );
	}

	solidroundrect( 223, 650, 1217, 870, 10, 10 );/*字体展示的框*/

	f = config_char( 24 );
	for( int i = 0; i < 13; i++ ){
		while( true ){
			m = GetMouseMsg();
			if( m.mkLButton == true ){
				FlushMouseMsgBuffer();
				break;
			}
		}
		fscanf( fp, "%s", str );
		solidrectangle( 263, 690, 820, 714 );	/*盖住之前显示的字*/
		outtextxy( 263, 690, str );

		switch( i ){
			case 0:
				photo( 540, 279, "calendar.jpg" );
				break;
			case 1:
				photo( 540, 279, "fu.jpg" );
				break;
			case 2:
				photo( 540, 279, "lung.jpg" );
				break;
			case 6:
				photo( 540, 279, "ran.jpg");
				break;
			case 8:
				photo( 345, 279, "hamre.jpg" );
				break;
			case 9:
				photo( 345, 279, "warning.jpg");
				break;
			case 10:
				photo( 345, 279, "exit.jpg");
				break;
			case 11:
				photo( 345, 279, "news.jpg" );
				break;
			default:
				break;
		}
		Sleep( 1000 );
	}
	fclose( fp );
}