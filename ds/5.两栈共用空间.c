#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

#define MAX_SIZE 8

#define SIZE(x) ( sizeof( x ) / sizeof( int ) )

typedef struct _ddsqStack{
	int data[ MAX_SIZE ];
	int top1;
	int top2;
}dsqStack;

void
initDstack( dsqStack **s );

void
destroyStack( dsqStack *s );

int
dstackEmpty( dsqStack *s );

int
push( dsqStack *s, int stack_tag, int e );

int
pop( dsqStack *s, int stack_tag, int *e );

int
main( int argc, int *argv[] )
{
	int i;
	int t;
	int a[] = { 0, 1, 2, 3, 4 };
	int b[] = { 5, 6, 7, 8, 9 };
	dsqStack *s;
	initDstack( &s );

	for( i = 0; i < SIZE(a); i++ ){
		if( FALSE == push( s, 1, a[i] ) ){
			printf("Õ»1Òç³ö\n");
			break;
		}
	}

	for( i = 0; i < SIZE(b); i++ ){
		if( FALSE == push( s, 2, b[i] ) ){
			printf("Õ»2Òç³ö\n");
			break;
		}
	}

	while( pop( s, 1, &t ) ){
		printf("%d ", t );
	}
	printf("\n");
	while( pop( s, 2, &t ) ){
		printf("%d ", t );
	}

	return 0;
}

void
initDstack( dsqStack **s )
{
	*s = ( dsqStack* )malloc( sizeof( dsqStack ) );
	(*s)->top1 = -1;
	(*s)->top2 = MAX_SIZE;
}

void
destroyStack( dsqStack *s )
{
	free( s );
}

int
dstackEmpty( dsqStack *s )
{
	return ( -1 == s->top1 && MAX_SIZE == s->top2 );
}

int
push( dsqStack *s, int stack_tag, int e )
{
	if( 1 == s->top2 - s->top1 ){
		return FALSE;
	}
	if( 1 == stack_tag ){
		s->data[ ++s->top1 ] = e;
	}else{
		s->data[ --s->top2 ] = e;
	}

	return TRUE;
}

int
pop( dsqStack *s, int stack_tag, int *e )
{
	if( 1 == stack_tag ){
		if( -1 == s->top1 ){
			return FALSE;
		}else{
			*e = s->data[ s->top1-- ];
		}
	}else{
		if( MAX_SIZE == s->top2 ){
			return FALSE;
		}else{
			*e = s->data[ s->top2++ ];
		}
	}

	return TRUE;
}