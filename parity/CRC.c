/*
**CRC_check by WWIandMC 2020/05/07
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

unsigned int
string_change_to_int( int *k );

int
count_bits( unsigned int n );

unsigned int
CRC_check( unsigned int a, unsigned int g, int k_a, int k_g );

void
print_binary( unsigned int a );


int
main( int argc, char *argv[] )
{
	int  k_a, k_g;
	unsigned int a;
	unsigned int g;
	printf("Enter the information bits:");
	a = string_change_to_int( &k_a );
	printf("Enter the POLY:");
	g = string_change_to_int( &k_g );
	a = CRC_check( a, g, k_a, k_g );
	print_binary( a );
	
	return 0;
}

unsigned int
string_change_to_int( int *k )
{
	int i = 0;
	unsigned int n = 0;
	unsigned int bit = 1;
	char buffer;
	char *str = ( char* )malloc( sizeof(char) );

	do{
		scanf("%c", &buffer);
		if( buffer == '\n' ){
			break;
		}
		realloc( str, i + 2 );
		str[i++] = buffer;
	}while(1);
	str[i] = '\0';

	*k = strlen( str );

	for( i = strlen(str) - 1; i >= 0; i-- ){
		if( str[i] == '1' ){
			n |= bit;
		}
		bit <<= 1;
	}

	free(str);
	return n;
}

unsigned int
CRC_check( unsigned int a, unsigned int g, int k_a, int k_g )
{
	int flag = 1;
	int remain_bits;
	int offset;
	int cnt = k_g - 1;
	
	unsigned int remain;

	do{
		if( flag ){
			flag = 0;
			remain = a ^ ( g << k_a - k_g );
		}else{
			remain ^= g;
		}
		remain_bits = count_bits( remain );
		offset = k_g - remain_bits;
		if( cnt > 0 ){
			if( offset <= cnt ){
				remain <<= offset;
				cnt -= offset;
			}else{
				remain <<= cnt;
				cnt = 0;
			}
		}
		print_binary( remain );
	}while( cnt > 0 || count_bits(remain) == k_g );
	a <<= k_g - 1;
	a |= remain;

	return a;
}

int
count_bits( unsigned int n )
{
	int cnt = 0;
	while( n != 0 ){
		n >>= 1;
		cnt++;
	}

	return cnt;
}

void
print_binary( unsigned int a )
{
	unsigned int bit = 1;
	bit <<= count_bits(a) - 1;
	while( bit != 0 ){
		if( a & bit ){
			printf("1");
		}else{
			printf("0");
		}
		bit >>= 1;
	}
	printf("\n");
}