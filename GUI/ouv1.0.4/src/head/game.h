#ifndef GAME_H_
#define GAME_H_

void
set_background( void );

void
set_infoblock( void );


ACL_Sound
load_29( void );

void
lazy_bar( int right );

void
case_report( FILE *fp );

void
research( FILE *fp , FILE *fp0 );

void
move( Date *date, Loc *xy );

void
time_change( Date *p );

void
trigger( Date *p );

#endif