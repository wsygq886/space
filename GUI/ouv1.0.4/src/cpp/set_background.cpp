#include "head.h"

void
set_background( void )
{
	LOGFONT t;

	cleardevice();			/*���֮ǰ���еĻ�ͼ�ۼ�*/

	setlinecolor( BLACK );	/*����ԲȦ�ı߿�Ϊ��ɫ*/

	/*���*/
	setfillcolor( TRACK_BACK );					/*���ɫ����Ϊ�궨��Ĺ����ɫ*/
	solidrectangle( 207, 170, 1207, 670 );		/*����ʵ��Բ�Ǿ���*/
	clearrectangle( 307, 270, 1107, 570 );		/*���һ��Բ�Ǿ��λ��ƻ�*/
	/*���*/

	/*ͼ��*/
	photo( 630, 370, "random.jpg");
	photo( 557, 124, "flag.jpg");
	photo( 857, 524, "flag.jpg" );
	photo( 64, 544, "unknown.jpg" );
	photo( 1098, 706, "action.jpg" );
	/*ͼ��*/

	/*����*/
	setfillcolor( INFO_COLOR );			/*������Ϣ����ɫ*/

	solidroundrect( 9, 10, 1098, 85, 10, 10 );
	t = config_char( 50 );
	outtextxy( 37, 23, _T("NEWS") );
	/*����*/

	/*ʱ��*/
	solidroundrect( 1138, 10, 1405, 86, 10, 10 );

	t = config_char( 32 );
	outtextxy( 1212, 32, _T("��") );
	outtextxy( 1286, 32, _T("��") );
	outtextxy( 1363, 32, _T("��") );
	/*ʱ��*/

	/*�Ʒְ���ж���*/
	solidroundrect( 20, 755, 283, 812, 10, 10 );	/*�ж���*/
	solidroundrect( 20, 832, 283, 889, 10, 10 );	/*�Ʒְ�*/

	t = config_char( 36 );
	outtextxy( 33, 765, _T("�ж���") );
	outtextxy( 33, 842, _T("�Ʒְ�") );
	/*�Ʒְ���ж���*/
}