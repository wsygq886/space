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
EXIT( const char *str );		/*FILEָ�������ʾ����*/

void
clear( void );					/*���������úڰ׽���*/

void
play( const char *name );		/*ֻ����һ�ε�����*/

void
photo( int x, int y, const char *name );	/*չʾͼƬ����*/

#endif

