#include <stdio.h>
#include <stdlib.h>

#define ElemType int

#define TRUE	1
#define FALSE	0

typedef struct _qnode{
	ElemType data;
	struct _qnode *next;
}qnode;

#define initQueue(rear) rear = NULL

void
destroyQueue( qnode *rear );

#define queueEmpty(rear) ( rear == NULL )

void
enQueue( qnode **rear, ElemType e );

int
deQueue( qnode **rear, ElemType *e );

int
main( ElemType argc, char **argv )
{
	int i;
	ElemType e;
	qnode *rear;
	initQueue(rear);
	for( i = 0; i < 10; i++ ){
		enQueue( &rear, i );
	}
	while( deQueue( &rear, &e ) ){
		printf("%d", e );
	}
	destroyQueue( rear );
	return 0;
}

void
enQueue( qnode **rear, ElemType e )
{
	qnode *n = ( qnode* )malloc( sizeof( qnode ) );
	n->data = e;
	if( *rear == NULL ){
		n->next = n;
		*rear = n;
	}else{
		n->next = (*rear)->next;
		(*rear)->next = n;
		*rear = n;
	}
}

int
deQueue( qnode **rear, ElemType *e )
{
	qnode *t;
	if( *rear == NULL ){
		return FALSE;
	}
	if( (*rear)->next == *rear ){	//原来的队列中只有一个结点
		*e = (*rear)->data;
		free( *rear );
		*rear = NULL;
	}else{
		t = (*rear)->next;
		*e = t->data;
		(*rear)->next = t->next;
		free( t );
	}
	return TRUE;
}

void
destroyQueue( qnode *rear )
{
	qnode *p, *t;
	if( rear != NULL ){
		p = rear->next;
		while( p != rear ){
			t = p->next;
			free( p );
			p = t;
		}
		free( rear );
	}
}