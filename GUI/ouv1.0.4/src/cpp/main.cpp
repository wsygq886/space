/*
**Develop by WWIandMC
**
**Latest version 2020/05/19
*/
#include "head.h"
#include "main.h"
#include <direct.h>

int point = 0;		/*行动点数*/
int score = 0;		/*得分*/

int
main( int argc, char *argv[] )
{
	ACL_Sound pm;
	MOUSEMSG m;
	
	_chdir( "./resource" );		/*改变当前工作目录到上一级的resource*/ 
	initgraph( 1440 , 900 );

	loadSound( "open_info.wma", &pm );
	playSound( pm, 1 );

	Welcome();

	while(true){
		m = GetMouseMsg();
		if( m.mkLButton == true ){
			if( 520 < m.x && m.x < 920 ){
				if( 567 < m.y && m.y < 640 ){
					/*
					**开始按钮
					*/
					open_info();
					stopSound( pm );
					switch ( game() ){
						case 0:end_info();break;
						case 1:interrupt();break;
						case 2:lazy_fault();break;
					}
					break;
				}else if( 690 < m.y && m.y < 763 ){
					/*
					**退出按钮
					*/
					break;
				}
			}
		}
	}
	closegraph();
	return 0;
}
