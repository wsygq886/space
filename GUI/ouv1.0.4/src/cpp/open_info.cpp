#include "head.h"

void
open_info( void )
{
	char		str[45];
	FILE		*fp;
	LOGFONT		f;
	MOUSEMSG	m;

	setbkcolor( RGB( 215, 193, 167 ) );		/*�����豸����ɫ*/
	setbkmode( INFO_COLOR );				/*�������屳��ɫ*/
	setfillcolor( INFO_COLOR );				/*����ͼ�����ɫ*/
	settextcolor( BLACK );					/*����������ɫ*/
	cleardevice();

	if( ( fp = fopen( "open_info.txt", "rb") ) == NULL ){
		EXIT( "open_info.txt not found" );
	}

	solidroundrect( 223, 650, 1217, 870, 10, 10 );/*����չʾ�Ŀ�*/

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
		solidrectangle( 263, 690, 820, 714 );	/*��ס֮ǰ��ʾ����*/
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