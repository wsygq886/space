#include "head.h"

void
set_background( void )
{
	LOGFONT t;

	cleardevice();			/*清除之前所有的绘图痕迹*/

	setlinecolor( BLACK );	/*设置圆圈的边框为黑色*/

	/*轨道*/
	setfillcolor( TRACK_BACK );					/*填充色设置为宏定义的轨道颜色*/
	solidrectangle( 207, 170, 1207, 670 );		/*绘制实心圆角矩形*/
	clearrectangle( 307, 270, 1107, 570 );		/*清除一个圆角矩形绘制环*/
	/*轨道*/

	/*图像*/
	photo( 630, 370, "random.jpg");
	photo( 557, 124, "flag.jpg");
	photo( 857, 524, "flag.jpg" );
	photo( 64, 544, "unknown.jpg" );
	photo( 1098, 706, "action.jpg" );
	/*图像*/

	/*新闻*/
	setfillcolor( INFO_COLOR );			/*设置信息栏颜色*/

	solidroundrect( 9, 10, 1098, 85, 10, 10 );
	t = config_char( 50 );
	outtextxy( 37, 23, _T("NEWS") );
	/*新闻*/

	/*时间*/
	solidroundrect( 1138, 10, 1405, 86, 10, 10 );

	t = config_char( 32 );
	outtextxy( 1212, 32, _T("年") );
	outtextxy( 1286, 32, _T("月") );
	outtextxy( 1363, 32, _T("日") );
	/*时间*/

	/*计分板和行动点*/
	solidroundrect( 20, 755, 283, 812, 10, 10 );	/*行动点*/
	solidroundrect( 20, 832, 283, 889, 10, 10 );	/*计分板*/

	t = config_char( 36 );
	outtextxy( 33, 765, _T("行动点") );
	outtextxy( 33, 842, _T("计分板") );
	/*计分板和行动点*/
}