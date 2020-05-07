/*
**(31,5)hamming_code by WWIandMC 2020/05/07
*/
#include <stdio.h>
#include <math.h>

#define LENGTH k + r

#define DEBUG1 0

void
count_r( int k, int *r );

void
insert_check_bits( int k, int r, char *a );

void
calu_check_bits( int* tmp, int length );

int
judge_check_bit( int i );

int
main( int argc, char *argv[] )
{
	int  k; 
	int  r = 2;
	int i;
	char a[33];
	/*
	**k为有效信息位数, 最大为26位
	**r为校验位位数, 最大为5位
	*/
	scanf("%26s%n", a+1, &k);
	/*
	**方便对下标进行处理, 字符串从下标1开始存放
	*/
	count_r( k, &r );
	insert_check_bits( k, r, a );
	calu_check_bits( a, k + r );

	for( i = 1; i <= LENGTH; i++ ){
		printf("%c", a[i]);
	}

	return 0;
}

void
count_r(  int k, int *r )
{
	while( k + 1 > pow(2,*r) - *r ){
		/*计算海明不等式*/
		*r += 1;
	}
}

int
judge_check_bit( int i, int r )
{
	int LOG;
	if( i > pow(2,r-1) ){
		return 0;
	}
	LOG = ( int )( log( i ) / log( 2 ) );
	if( pow( 2, LOG ) == i ){
		return 1;
	}else{
		return 0;
	}
}

void
insert_check_bits( int k, int r, char *a )
{
	int t_boundary = k;/*临时边界, 随着校验位的插入长度会越来越大*/
	int  i, j;
	for( i = 1; i <= LENGTH; i++ ){ 
		if( judge_check_bit( i, r ) ){
			for( j = t_boundary; j >= i; j-- ){
				a[j+1] = a[j];
			}
			t_boundary++;
			a[i] = '2';/*用字符2来标记校验位*/
		}
	}
	a[LENGTH+1] = '\0';

	#if DEBUG1
	for( i = 1; i <= LENGTH; i++ ){
		printf("%c", a[i]);
	}
	printf("\n");
	#endif
}

void
calu_check_bits( char *a, int length )
{
	int i, j;
	int flag;
	char check_bit;
	unsigned int bit = 1;
	for( i = 0; pow(2,i) <= length; i++ ){
		flag = 1;
		for( j = 3; j <= length; j++ ){
			if( a[j] != '2' ){
				if( j & bit ){
					/*
					**以位来判断是否满足条件, 例如3 = 1 + 2, 二进制数为11, 3 & 1和3 & 2得到的结果都是非零
					*/
					if( flag ){
						check_bit = a[j];
						flag = 0;
					}else{
						check_bit = (check_bit - '0') ^ ( a[j] - '0' ) + '0';
					}
				}
			}
		}
		a[(int)pow(2,i)] = check_bit;
		bit <<= 1;
	}
}