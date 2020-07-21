#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

#define SIZE	5

typedef struct _cyQueue{
	int data[SIZE];
	int front, rear;
}cyQueue;

void
initQueue( cyQueue **q );

#define destroyQueue(q) free(q)

#define queueEmpty(q) ( q->front == q->rear )

int
enQueue( cyQueue *q, int e );

int
deQueue( cyQueue *q, int *e );

int
main( int argc, char **argv )
{
	int i = 0;
	int e;
	cyQueue *q;
	initQueue( &q );
	while( enQueue( q, i++ ) ){
		;
	}
	while( deQueue( q, &e ) ){
		printf("%d", e );
	}

	while( enQueue( q, i++ ) ){
		;
	}
	while( deQueue( q, &e ) ){
		printf("%d", e );
	}

	destroyQueue( q );
	return 0;
}

void
initQueue( cyQueue **q )
{
	*q = ( cyQueue* )malloc( sizeof( cyQueue ) );
	(*q)->front = (*q)->rear = 0;
}

int
enQueue( cyQueue *q, int e )
{
	if( ( q->rear + 1 ) % SIZE == q->front ){
		return FALSE;
	}
	q->rear = ( q->rear + 1 ) % SIZE;
	q->data[ q->rear ] = e;
	return TRUE;
}

int
deQueue( cyQueue *q, int *e )
{
	if( q->rear == q->front ){
		return FALSE;
	}
	q->front = ( q->front + 1 ) % SIZE;
	*e = q->data[ q->front ];

	return TRUE;
}