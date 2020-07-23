#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

#define SIZE	5

typedef struct _cyQueue{
	int data[ SIZE ];
	int front;
	int cnt;
}cyQueue;

void
initQueue( cyQueue **q );

#define destroyQueue(q) free(q)

#define queueEmpty(q) ( q->cnt == 0 )

int
enQueue( cyQueue *q, int e );

int
deQueue( cyQueue *q, int *e );

int
main( int argc, char **argv )
{
	int i;
	int e;
	cyQueue *q;
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
initQueue( cyQueue **q )
{
	*q = ( cyQueue* )malloc( sizeof( cyQueue ) );
	(*q)->front = (*q)->cnt = 0;
}

int
enQueue( cyQueue *q, int e )
{
	int rear;
	if( q->cnt == SIZE ){
		return FALSE;
	}else{
		rear = ( q->front + q->cnt ) % SIZE;
		rear = ( rear + 1 ) % SIZE;
		q->data[ rear ] = e;
		q->cnt++;
		return TRUE;
	}
}

int
deQueue( cyQueue *q, int *e )
{
	if( q->cnt == 0 ){
		return FALSE;
	}else{
		q->front = ( q->front + 1 ) % SIZE;
		*e = q->data[ q->front ];
		q->cnt--;
		return TRUE;
	}
}