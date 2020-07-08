#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int value;
	struct _node *next;
}linkList;

void
initList( linkList **l );

void
createList( linkList *l, int *a, int n );

void
destroyList( linkList *l );

void
sort( linkList *l );

void
split( linkList *l, linkList **l2 );

void
delmaxnode( linkList *l );

void
printList( linkList *l );

void
reverse( linkList *l );

void
move( linkList *l );

void
reverse2( linkList *l );

int
main( int argc, char **argv )
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	linkList *l, *l2;
	initList( &l );
	createList( l, a, sizeof( a )/ sizeof( int ) );
	reverse2( l );
	printList( l );

	destroyList( l );

	return 0;
}

void
initList( linkList **l )
{
	( *l ) = ( linkList* )malloc( sizeof( linkList ) );
	( *l )->next = NULL;
}

void
createList( linkList *l, int *a, int n )
{
	int i;
	linkList *p, *tail = l;
	for( i = 0; i < n; i++ ){
		p = ( linkList* )malloc( sizeof( linkList ) );
		p->value = a[i];
		tail->next = p;
		tail = p;
	}
	tail->next = NULL;
}

void
destroyList( linkList *l )
{
	linkList *p;
	for( l = l->next; l != NULL; l = p ){
		p = l->next;
		free( l );
	}
	free( l );
}

void
sort( linkList *l )
{
	linkList *p, *pre, *q;
	p = l->next->next;			// pָ��L�ĵ�2�����ݽڵ�
	l->next->next = NULL;		// ����ֻ��һ�����ݽڵ�������, ��L��ֳ�������
	
	while( p != NULL ){
		q = p->next;			// q����*p�ڵ��̽ڵ��ָ��
		pre = l;				// �������ͷ���бȽ�, preָ�����*p��ǰ���ڵ�
		while( pre->next != NULL && pre->next->value < p->value ){
			pre = pre->next;	// ����������Ҳ���*p��ǰ���ڵ�*pre
		}
		p->next = pre->next;
		pre->next = p;
		p = q;					// ɨ��ԭ���������µĽڵ�
	}
}

void
split( linkList *l, linkList **l2 )
{
	linkList *p;
	( *l2 ) = ( linkList* )malloc( sizeof( linkList ) );
	( *l2 )->next = NULL;

	for( l = l->next; l != NULL && l->next != NULL; l = p ){
		p = l->next->next;
		l->next->next = ( *l2 )->next;
		( *l2 )->next = l->next;
		l->next = p;
	}
}

void
delmaxnode( linkList *l )
{
	linkList *p = l->next, *pre = l;
	linkList *maxp = p, *maxpre = pre;
	while( p != NULL ){
		if( maxp->value < p->value ){
			maxp = p;
			maxpre = pre;
		}
		pre = p;
		p = p->next;
	}
	maxpre->next = maxp->next;
	free( maxp );
}

void
printList( linkList *l )
{
	for( l = l->next; l != NULL; l = l->next ){
		printf("%d ", l->value);
	}
}

void
reverse( linkList *l )
{
	linkList *p = l->next, *q;
	l->next = NULL;
	while( p != NULL ){
		q = p->next;
		p->next = l->next;
		l->next = p;
		p = q;
	}
}

void
move( linkList *l )
{
	linkList *l1 = NULL, *l2 = NULL;
	linkList *r, *r1, *r2, *p;
	p = l->next;
	r = l;

	while( p != NULL ){
		if( p->value == 0 ){
			r->next = p;
			r = p;
		}else if( p->value == 1 ){
			if( l1 == NULL ){	// l1����ͷ�ڵ�, Ҫ�����⴦���һ�����
				l1 = p;
				r1 = p;
			}else{
				r1->next = p;
				r1 = p;
			}
		}else{
			if( l2 == NULL ){
				l2 = p;
				r2 = p;
			}else{
				r2->next = p;
				r2 = p;
			}
		}
		p = p->next;
	}

	r->next = r1->next = r2->next = NULL;
	r->next = l1;
	r1->next = l2;
}

void
reverse2( linkList *l )
{
	linkList *current, *rear, *front;

	rear = l->next;
	current = rear->next;
	rear->next = NULL;
	front = current->next;

	while( 1 ){
		current->next = rear;
		if( front == NULL ){
			break;
		}
		rear = current;
		current = front;
		front = front->next;
	}
	l->next = current;
}