#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *prior;
	struct Node *next;
}node;

void
initList( node **l );

void
createList( node **l, int *a, int n );

void
listInsert( node *l, int e );

void
headDelete( node **l );

void
tailDelete( node *l );

void
printList( node *l );


int
main( int argc, char *argv[] )
{
	int a[] = { 0, 1, 2, 3, 4};
	node *l;
	initList( &l );
	createList( &l, a, sizeof(a) / sizeof(int));
	//headDelete( &l );
	//tailDelete( l );
	listInsert( l, -1 );
	printList( l );

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
		if( i > 0 ){
			s->prior = tail;
		}
		tail = s;
	}
	tail->next = *l;
	(*l)->prior = tail;
}

void
headDelete( node **l )
{
	node *t = *l;
	(*l)->prior->next = (*l)->next;
	(*l)->next->prior = (*l)->prior;
	*l = (*l)->next;
	free( t );
}

void
tailDelete( node *l )
{
	node *t = l->prior;
	l->prior->prior->next = l;
	l->prior = l->prior->prior;
	free( t );
}

void
listInsert( node *l, int e )
{
	node *s;
	s = ( node* )malloc( sizeof( node ) );
	s->data = e;
	s->next = l;
	l->prior->next = s;
	s->prior = l->prior;
	l->prior = s;
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