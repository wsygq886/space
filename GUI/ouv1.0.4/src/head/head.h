/*
**Develop by WWIandMC
**
**Latest version 2020/05/19
*/
#ifndef HEAD_H_
#define HEAD_H_

#include <easyx.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define DEL 2
#define TRACK_BACK	RGB( 255, 218, 171 )
#define INFO_COLOR	RGB( 255, 229, 198 )

extern int point;
extern int score;

/*ACLlib*/
typedef int ACL_Sound;

void
loadSound(const char *fileName, ACL_Sound *pSound);

void
playSound(ACL_Sound soundID, int repeat);

void
stopSound(ACL_Sound soundID);
/*ACLlib*/

typedef struct _date{
	int year;
	int month;
	int day;
}Date;

typedef struct _location{
	int x;
	int y;
}Loc;


LOGFONT
config_char( int height );

void
EXIT( const char *str );		/*FILE指针错误提示代码*/

void
clear( void );					/*清屏并设置黑白界面*/

void
play( const char *name );		/*只播放一次的声音*/

void
photo( int x, int y, const char *name );	/*展示图片函数*/

#endif

