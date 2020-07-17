#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

#define MAX_SIZE 100

typedef struct _sqStack{
	char data[ MAX_SIZE ];
	int top;
}sqStack;

void
initStack( sqStack **s );

void
destroyStack( sqStack *s );

int
stackEmpty( sqStack *s );

int
push( sqStack *s, char e );

int
pop( sqStack *s, char *e );

int
getTop( sqStack *s, char *e );

int
main( int argc, char *argv[] )
{
	int i;
	int flag = TRUE;
	char str[] = "AGCTTCGA";
	const char *info[] = { "NO", "YES"};

	sqStack *s;
	initStack( &s );

	for( i = 0; i < strlen( str ); i++ ){
		if( FALSE == push( s, str[i] ) ){
			printf("栈上溢出");
			break;
		}
	}

	for( i = 0; i < strlen( str ); i++ ){
		char temp;
		if( FALSE == pop( s, &temp ) ){
			printf("栈下溢出");
			break;
		}
		if( str[i] != temp ){
			flag = FALSE;
			break;
		}
	}
	printf("%s\n", info[ flag ] );

	destroyStack( s );

	return 0;
}

void
initStack( sqStack **s )
{
	*s = ( sqStack* )malloc( sizeof( sqStack ) );
	(*s)->top = -1;
}

void
destroyStack( sqStack *s )
{
	free( s );
}

int
stackEmpty( sqStack *s )
{
	return ( -1 == s->top );
}

int
push( sqStack *s, char e )
{
	if( MAX_SIZE - 1 == s->top ){
		return FALSE;
	}
	s->data[ ++s->top ] = e;

	return TRUE;
}

int
pop( sqStack *s, char *e )
{
	if( -1 == s->top ){
		return FALSE;
	}
	*e = s->data[ s->top-- ];

	return TRUE;
}

int
getTop( sqStack *s, char *e )
{
	if( -1 == s->top ){
		return FALSE;
	}
	*e = s->data[ s->top ];
	
	return TRUE;
}