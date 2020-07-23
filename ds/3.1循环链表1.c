#include <stdio.h>
#include <stdlib.h>

void
input( int *a, int *n );

int
compare( void const *a, void const *b );

void
print( int *a, int n );

int
main( int argc, char *argv[] )
{
	int n_a, n_b;
	int a[20], b[20], c[40];
	input( a, &n_a );
	input( b, &n_b );
	qsort( a, sizeof(a), sizeof(a)/sizeof(int), compare );
	print( a, n_a );


	return 0;
}

void
input( int *a, int *n )
{
	int i;
	scanf("%d", n);
	for( i = 0; i < *n; i++ ){
		scanf("%d", &a[i]);
	}
}

int
compare( void const *a, void const *b )
{
	return ( *((int*)a) > *((int*)b) ? 0 : 1 );
}

void
print( int *a, int n )
{
	int i;
	for( i = 0; i < n; i++ ){
		printf("%d ", a[i]);
	}
}