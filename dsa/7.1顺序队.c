#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

#define SIZE	5

typedef struct _sqQueue{
	int data[ SIZE ];
	int front, rear;
}sqQueue;

void
initQueue( sqQueue **q );

#define destroyQueue(q) free(q)

#define queueEmpty(q) ( q->front == q->rear )

int
enQueue( sqQueue *q, int e );

int
deQueue( sqQueue *q, int *e );

int
main( int argc, char **argv )
{
	int i;
	int e;
	sqQueue *q;
	initQueue( &q );
	for( i = 1; i <= 5; i++ ){
		enQueue( q, i ); 
	}
	while( deQueue( q, &e ) ){
		printf("%d", e );
	}

	destroyQueue( q );
	return 0;
}

void
initQueue( sqQueue **q )
{
	*q = ( sqQueue* )malloc( sizeof( sqQueue ) );
	(*q)->front = (*q)->rear = -1;
}

int
enQueue( sqQueue *q, int e )
{
	if( q->rear == SIZE - 1 ){
		return FALSE;
	}
	q->data[ ++q->rear ] = e;
	return TRUE;
}

int
deQueue( sqQueue *q, int *e )
{
	if( q->front == q->rear ){
		return FALSE;
	}
	*e = q->data[ ++q->front ];
	return TRUE;
}