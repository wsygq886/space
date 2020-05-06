#include <stdio.h>
#include <string.h>

void
sort (void *Array, int n_values, int size, int (*compare)( void *a, void *b ) );
/*
**为了能接受不同类型的参数，数组的类型应声明为void*，同时compare指向的函数的参数列表也应如此
*/

int
compare_int ( void *a, void *b );

void
swap ( void *a, void *b );

int
main( int argc, char *argv[] )
{
	
	char a[5] = "dcab";

	int  b[5] = {9,15,2,-1,5};
	int  *p   = b;

	sort( a, strlen(a), sizeof(char), strcmp );
	/*
	**此处编译器报错的原因是strcmp的参数声明是char*不是void*
	*/
	sort( b, sizeof(b) / sizeof(int), sizeof(int) , compare_int);

	printf("%s\n", a);

	while( p <= &b[4] ){
		printf("%d ", *p++);
	}

	return 0;
}

void
sort( void *Array, int n_values, int element_size, int (*compare)( void *a, void *b ) )
{
	int i, j;
	int cnt;
	int exchange;

	char *ap = ( char* )Array;  /*当成char来处理，把数据类型分解为字节来处理*/

	for( i = 1; i < n_values; i++ ){
		exchange = 1;
		for( j = n_values - 1; j >= i; j-- ){
			if( compare( ap + element_size * j, ap + element_size * (j-1) ) < 0 ){
				/*
				**element_size * j 作为指针的偏移量
				*/
				exchange = 0;
				for( cnt = 0; cnt < element_size; cnt++ ){
					/*
					**cnt = 0...element_size分别对应了数据类型的第一个字节第二个字节
					*/
					swap( ap + element_size * j + cnt , ap + element_size * (j-1) + cnt );
				}
			}
		}
		if(exchange)break;
	}
}

int
compare_int ( void *a, void *b )
{
	if( *( int* )a == *( int* )b ){
		return 0;
	}else if( *( int* )a  < *( int* )b ){
		return -1;
	}else{
		return 1;
	}
}

void
swap ( void *a, void *b )
{
	char tmp = *(char*)a;
	*( char* )a = *( char* )b;
	*( char* )b = tmp;
}