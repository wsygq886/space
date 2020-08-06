#include <stdio.h>
#include <stdlib.h>

void
hanoi( int n, char from, char buffer, char to )
{
	if( n == 0 ){
		return;
	}
	hanoi( n-1, from, to, buffer );
	printf("Move disk from %c to %c\n", from, to );
	hanoi( n-1, buffer, from, to );
}


int
main( void )
{
	int n;
	scanf("%d", &n);
	hanoi( n, 'a', 'b', 'c' );

	return 0;
}