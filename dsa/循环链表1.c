#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

void
initList( node **l );

void
createList( node **l, int *a, int n );

void
listInsert( node **l, int e );

void
listDelete( node *l );

void
printList( node *l );

int
main( int argc, char *argv[] )
{
	int a[] = { 0, 1, 2, 3, 4};
	node *l;
	initList( &l );
	createList( &l, a, sizeof(a) / sizeof(int));
	listInsert( &l, 5 );
	listDelete( l );

	return 0;
}

void
initList( node **l )
{
	(*l) = ( node* )malloc( sizeof( node ) );
}


void
createList( node **l, int *a, int n )
{
	int i;
	node *s, *tail = *l;

	for( i = 0; i < n; i++ ){
		if( i == 0 ){
			s = *l;
		}else{
			s = ( node* )malloc( sizeof( node ) );
		}
		s->data = a[i];
		tail->next = s;
		tail = s;
	}
	tail->next = *l;
	*l = tail;
}

void
listInsert( node **l, int e )
{
	node *s;
	s = ( node* )malloc( sizeof( node ) );
	s->data = e;
	s->next = (*l)->next;
	(*l)->next = s;
	*l = s;
}

void
listDelete( node *l )
{
	node *t;
	t = l->next;
	l->next = l->next->next;
	free( t );
}

void
printList( node *l )
{
	node *p = l;
	if( p != NULL ){
		do{
			printf("%d ", p->data );
			p = p->next;
		}while( p != l );
	}
}