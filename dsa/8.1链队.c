#include <stdio.h>
#include <stdlib.h>

#define ElemType int

#define TRUE	1
#define FALSE	0

typedef struct _qnode{
	ElemType data;
	struct _qnode *next;
}qnode;

typedef struct _lQueue{
	qnode *front;
	qnode *rear;
}lQueue;

void
initQueue( lQueue **q );

void
destroyQueue( lQueue *q );

void
queueEmpty( lQueue *q );

void
enQueue( lQueue *q, ElemType e );

int
deQueue( lQueue *q, ElemType *e );


int
main( ElemType argc, char **argv )
{
	int i;
	lQueue *q;
	initQueue( &q );
	for( i = 0; i < 10; i++ ){
		enQueue( q, i );
	}
	destroyQueue( q );

	return 0;
}

void
initQueue( lQueue **q )
{
	*q = ( lQueue* )malloc( sizeof( lQueue ) );
	(*q)->front = (*q)->rear = NULL;
}

void
destroyQueue( lQueue *q )
{
	while( q->front ){
		q->rear = q->front->next;
		free( q->front );
		q->front = q->rear;
	}
	free( q );
}

void
enQueue( lQueue *q, ElemType e )
{
	qnode *p = ( qnode* )malloc( sizeof( qnode ) );
	p->data = e;
	p->next = NULL;
	if( q->rear == NULL ){
		q->front = q->rear = p;
	}else{
		q->rear->next = p;
		q->rear = p;
	}
}

int
deQueue( lQueue *q, ElemType *e )
{
	qnode *t;
	if( q->rear == NULL ){				//队列为空
		return FALSE;
	}
	t = q->front;
	if( q->front == q->rear ){			//队列只有一个数据结点
		q->front = q->rear = NULL;
	}else{
		q->front = q->front->next;
	}
	*e = q->front->data;
	free(t);
	return TRUE;
}

void
queueEmpty( lQueue *q )
{
	return ( q->rear == NULL );
}