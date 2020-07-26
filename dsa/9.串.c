#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

typedef struct _strnode{
	char ch;
	struct _strnode *next;
}strnode;

void
initString( strnode **s );

void
createString( strnode *s, const char *cstr );

void
replace( strnode *s );

void
printString( strnode *s );

int
main( int argc, char **argv )
{
	strnode *s;
	initString( &s );
	createString( s, "disable" );
	printString(s);
	replace(s);
	printString(s);

	return 0;
}

void
initString( strnode **s )
{
	*s = ( strnode* )malloc( sizeof( strnode ) );
}

void
createString( strnode *s, const char *cstr )
{
	int i;
	strnode *p, *tail = s;
	for( i = 0; cstr[i] != '\0'; i++ ){
		p = ( strnode* )malloc( sizeof( strnode ) );
		p->ch = cstr[i];
		tail->next = p;
		tail = p;
	}
	tail->next = NULL;
}

void
replace( strnode *s )
{
	int exit = FALSE;
	strnode *p;
	for( s = s->next; s->next != NULL; s = s->next ){
		if( s->ch == 'a' && s->next->ch == 'b' ){
			exit = TRUE;
			break;
		}
	}
	if( exit ){
		s->ch = 'x';
		s->next->ch = 'z';
		p = ( strnode* )malloc( sizeof( strnode ) );
		p->ch = 'y';
		p->next = s->next;
		s->next = p;
	}
}

void
printString( strnode *s )
{
	for( s = s->next; s != NULL; s = s->next ){
		printf("%c", s->ch );
	}
	printf("\n");
}