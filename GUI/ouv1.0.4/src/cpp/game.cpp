#include "head.h"
#include "game.h"
#include "output.h"

int
game( void )
{
	ACL_Sound	concern, iron;
	MOUSEMSG	m;
	FILE		*fp1, *fp2, *fp3;
	Date		time = { 2019, 12, 15 };
	Loc			xy = { 257, 225 };
	
	bool		research_open = false;
	bool		report_open = false;
	bool		is_move = false;

	loadSound( "music.wma", &concern );
	playSound( concern, 1 );

	set_background();
	set_infoblock();

	output_time( &time );
	output_score_point();
	
	if( ( fp1 = fopen( "research.txt", "rb" ) ) == NULL ){
		EXIT("research.txt not found");
	}else if( ( fp2 = fopen( "policy.txt", "rb" ) ) == NULL ){ 
		EXIT( "policy.txt not found" );
	}else if( ( fp3 = fopen( "data.txt", "rb" ) ) == NULL ){
		EXIT( "data.txt not found" );
	}

	while( time.month != 4 || time.day != 15 ){
		m = GetMouseMsg();
		if( m.mkLButton == true ){
			if( m.mkCtrl == true ){
				/*
				**中途退出, 返回标志1
				*/
				stopSound( concern );
				return 1;
			}
			if( 570 < m.x && m.x < 770 && 395 < m.y && m.y < 495 && is_move == false ){
				move( &time, &xy );
				time_change( &time );
				output_time( &time );
				trigger( &time );
				is_move = true;
				
				if( ( xy.x == 557 && xy.y == 225 ) || ( xy.x == 857 && xy.y == 625 ) ){
					point += 10;
				}

				if( time.month == 1 && time.day == 29 ){
					stopSound(concern);
					iron = load_29();
					/*
					**单曲循环的曲目要保留曲面ID
					*/
				}

				if( 363 + point * 28 >= 1010 ){
					/*
					**怠惰值大于等于1010游戏结束, 返回标志2
					*/
					lazy_bar( 1010 );		/*直接填满条*/
					Sleep(3000);			/*挂起让用户看到*/
					stopSound( concern );
					return 2;
				}

				if( time.month == 12 && time.day == 29 ){
					research_open = true;
					photo( 1098, 806, "research.jpg");
				}
				
				if( time.month == 1 && time.day == 15 ){
					report_open = true;
				}

				if( report_open ){
					case_report( fp3 );
				}

				output_score_point();
			}

			if( 1098 < m.x && m.x < 1364 && point ){
				if( 806 < m.y && m.y < 880 && research_open ){
					research( fp1, fp2);
					is_move = false;
				}else if( 706 < m.y && m.y < 780 ){
					research( fp2, fp1 );
					is_move = false;
				}
			}

			if( 363 + point * 28 < 1010 ){
				lazy_bar( 363 + point * 28 );
			}
		}
		FlushMouseMsgBuffer();
	}
	fclose( fp1 );
	fclose( fp2 );
	fclose( fp3 );
	stopSound( iron );

	return 0;
}