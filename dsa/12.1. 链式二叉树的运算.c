#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
	char data;
	struct _btnode *lchild, *rchild;
}btnode;

typedef struct _qnode{
	btnode *address;
	struct _qnode *next;
}qnode;

typedef struct _lQueue{
	qnode *front;
	qnode *rear;
}lQueue;

void
enQueue( lQueue *q, btnode *e );

int
deQueue( lQueue *q );

void
createTree( btnode **t );

void
destroyTree( btnode *t );

int
PostOrderGetHeight( btnode *bt );

void
PreOrderTraversal( btnode *bt );

void
InOrderTraversal( btnode *bt );

void
PostOrderTraversal( btnode *bt );

void
LevelOrderTraversal( btnode *bt );


int
main( void )
{
	btnode *t;
	createTree( &t );
	PreOrderTraversal( t );
	destroyTree( t );

	return 0;
}

void
enQueue( lQueue *q, btnode *e )
{
	qnode *p = ( qnode* )malloc( sizeof( qnode ) );
	p->address = e;
	p->next = NULL;
	if( q->rear == NULL ){
		q->front = q->rear = p;
	}else{
		q->rear->next = p;
		q->rear = p;
	}
}

int
deQueue( lQueue *q )
{
	qnode *t;
	if( q->rear == NULL ){
		return 1;
	}
	t = q->front;
	if( q->front == q->rear ){
		q->front = q->rear = NULL;
	}else{
		q->front = q->front->next;
	}
	printf("%c ", t->address->data);
	free( t );

	return 0;
}

void
createTree( btnode **t )
{
	char ch;
	scanf("%c", &ch);
	if( ch == '#' ){
		*t = NULL;
	}else{
		*t = ( btnode* )malloc( sizeof( btnode ) );
		(*t)->data = ch;
		createTree( &( (*t)->lchild ) );
		createTree( &( (*t)->rchild ) );
	}
}

void
destroyTree( btnode *t )
{
	if( t == NULL ){
		return;
	}
	destroyTree( t->lchild );
	destroyTree( t->rchild );
	free( t );
}

void
PreOrderTraversal( btnode *bt )
{
	if( bt == NULL ){
		return;
	}
	printf("%c", bt->data);
	PreOrderTraversal( bt->lchild );
	PreOrderTraversal( bt->rchild );
}

void
InOrderTraversal( btnode *bt )
{
	if( bt == NULL ){
		return;
	}
	InOrderTraversal( bt->lchild );
	printf("%c", bt->data);
	InOrderTraversal( bt->rchild );
}

void
PostOrderTraversal( btnode *bt )
{
	if( bt == NULL ){
		return;
	}
	PostOrderTraversal( bt->lchild );
	PostOrderTraversal( bt->rchild );
	printf("%c", bt->data);
}

void
LevelOrderTraversal( btnode *bt )
{
	btnode *t;
	lQueue *q;

	do{
		//初始化一个链队
		q = ( lQueue* )malloc( sizeof( lQueue ) );
		q->front = q->rear = NULL;
	}while(0);

	if( bt == NULL ){	//若为空树直接返回
		return;
	}

	enQueue( q, bt );	//根节点进队

	while( q->rear != NULL ){
		btnode *t = q->front->address;	//队头的树节点
		if( t->lchild ){
			/* 有左孩子则进队*/
			enQueue( q, t->lchild );
		}
		if( t->rchild ){
			/* 有右孩子则进队 */
			enQueue( q, t->rchild );
		}
		deQueue( q );
	}
}

int
PostOrderGetHeight( btnode *bt )
{
	int h_left, h_right;
	if( bt == NULL ){
		return 0;
	}
	h_left = PostOrderGetHeight( bt->lchild );
	h_right = PostOrderGetHeight( bt->rchild );

	return ( h_left > h_right ) ? ( h_left + 1 ) : ( h_right + 1 );
}

