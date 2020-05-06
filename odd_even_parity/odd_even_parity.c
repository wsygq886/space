#include <stdio.h>

int
count_one_bits( int a );

void
print_binary( int a );

void
odd_parity_out( int cnt, int a );

void
even_parity_out( int cnt, int a );

int
main( int argc, char *argv[] )
{
	int a;
	int cnt;
	scanf("%d", &a);

	cnt = count_one_bits(a);

	odd_parity_out ( cnt, a );
	even_parity_out( cnt, a );

	return 0;
}

int
count_one_bits( int a )
{
	int cnt = 0;
	for( cnt = 0; a != 0; a >>= 1){
		if( ( a & 1 ) != 0 ){
			cnt++;
		}
	}

	return cnt;
}

void
print_binary( int a )
{
	unsigned int b = 1;
	int start = 0;
	b <<= 31;
	do{
		if( a & b ){
			start = 1;
			printf("1");
		}else if( start ){
			printf("0");
		}
		b >>= 1;
	}while( b != 0 );
}


void
odd_parity_out( int cnt, int a )
{
	printf("Odd:\t");
	print_binary(a);
	printf("%d\n", !(cnt & 1) );
}

void
even_parity_out( int cnt, int a )
{
	printf("Even:\t");
	print_binary(a);
	printf("%d\n", cnt & 1 );
}