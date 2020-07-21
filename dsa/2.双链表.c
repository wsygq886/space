#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

typedef struct Dnode{
	int data;
	struct Dnode *prior;
	struct Dnode *next;
}dnode;

void
initList( dnode **l );

void
createList1( dnode *l, int *a, int n );

void
createList2( dnode *l, int *a, int n );

int
listInsert( dnode *l, int i, int e );

int
listDelete( dnode *l, int i );

void
printList( dnode *l );

int
main( int argc, char **argv )
{
	int a[] = { 0, 1, 2, 3 };
	dnode *l;
	initList( &l );
	createList2( l, a, sizeof(a)/sizeof(int));
	listInsert( l, 2, 5 );
	listDelete( l, 2 );
	printList( l );

	return 0;
}

void
initList( dnode **l )
{
	( *l ) = ( dnode* )malloc( sizeof( dnode ) );
}

void
createList1( dnode *l, int *a, int n )
{
	int i;
	dnode *s;
	l->prior = l->next = NULL;

	for( i = 0; i < n; i++ ){
		s = ( dnode* )malloc( sizeof( dnode ) );
		s->data = a[i];
		s->next = l->next;
		if( l->next != NULL ){
			l->next->prior = s;
		}
		l->next = s;
		s->prior = l;
	}
}

void
printList( dnode *l )
{
	for( l = l->next; l != NULL; l = l->next ){
		printf("%d ", l->data);
	}
}

void
createList2( dnode *l, int *a, int n )
{
	int i;
	dnode *s, *tail = l;
	for( i = 0; i < n; i++ ){
		s = ( dnode* )malloc( sizeof( dnode ) );
		s->data = a[i];
		tail->next = s;
		s->prior = tail;
		tail = s;
	}
	tail->next = NULL;
}

int
listInsert( dnode *l, int i, int e )
{
	int j = 0;
	dnode *s;
	while( j < i - 1 && l != NULL ){
		j++;
		l = l->next;
	}
	if( l == NULL ){
		return FALSE;
	}else{
		s = ( dnode* )malloc( sizeof( dnode ) );
		s->data = e;
		s->next = l->next;
		if( l->next != NULL ){
			l->next->prior = s;
		}
		s->prior = l;
		l->next = s;
		return TRUE;
	}
}

int
listDelete( dnode *l, int i )
{
	int j = 0;
	dnode *q;

	while( j < i - 1 && l != NULL ){
		j++;
		l = l->next;
	}
	if( l == NULL ){
		return FALSE;
	}else{
		q = l->next;
		if( q == NULL ){
			return FALSE;
		}
		l->next = q->next;
		if( l->next != NULL ){
			l->next->prior = l;
		}
		free( q );
		return TRUE;
	}
}