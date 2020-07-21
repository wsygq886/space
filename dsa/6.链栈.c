#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

typedef struct _lstack{
	char data;
	struct _lstack *next;
}lstack;

void
initStack( lstack **s );

void
destroyStack( lstack *s );

int
stackEmpty( lstack *s );

void
push( lstack *s, char e );

int
pop( lstack *s, char *e );

int
getTop( lstack *s, char *e );

int
main( int argc, char **argv )
{
	char ch;
	lstack *s;
	initStack( &s );
	push( s, 'a' );
	push( s, 'b' );
	push( s, 'c' );
	pop( s, &ch );
	printf("%c", ch);
	pop( s, &ch );
	printf("%c", ch);
	pop( s, &ch );
	printf("%c", ch);
	destroyStack( s );

	return 0;
}

void
initStack( lstack **s )
{
	*s = ( lstack* )malloc( sizeof( lstack ) );
	(*s)->next = NULL;
}

void
destroyStack( lstack *s )
{
	lstack *t;
	while( s != NULL ){
		t = s->next;
		free( s );
		s = t;
	}
}

int
stackEmpty( lstack *s )
{
	return ( s->next == NULL );
}

void
push( lstack *s, char e )
{
	lstack *r = ( lstack* )malloc( sizeof( lstack ) );
	r->data = e;
	r->next = s->next;
	s->next = r;
}

int
pop( lstack *s, char *e )
{
	lstack *t;
	if( s->next == NULL ){
		return FALSE;
	}
	t = s->next;
	*e = t->data;
	s->next = t->next;
	free( t );
	return TRUE;
}

int
getTop( lstack *s, char *e )
{
	if( s->next == NULL ){
		return FALSE;
	}
	*e = s->next->data;
	return TRUE;
}