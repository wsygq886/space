/*
**odd_even_parity by WWIandMC 2020/05/06
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*
odd_parity( char *a, int cnt, int i );

char*
even_parity( char *a, int cnt, int i );

int
main( int argc, char *argv[] )
{
	int i = 0;
	int cnt = 0;
	char buffer;
	char *a = (char*)malloc(sizeof(char));
	do{
		scanf("%c", &buffer);
		realloc( a , i + 2);
		if( buffer == '\n' ){
			break;
		}
		a[i++] = buffer;
		if( buffer == '1' ){
			cnt++;
		}
	}while(1);
	a[i] = '\0';

	printf("odd: %s\n", odd_parity(a,cnt,i));
	printf("even:%s\n", even_parity(a,cnt,i));

	return 0;
}

char*
odd_parity( char *a, int cnt, int i )
{
	if( strlen(a) != 0 ){
		if( cnt & 1 ){
			a[i++] = '0';
		}else{
			a[i++] = '1';
		}
		a[i] = '\0';
	}

	return a;
}

char*
even_parity( char *a, int cnt, int i )
{
	if( strlen(a) != 0 ){
		if( cnt & 1 ){
			a[i++] = '1';
		}else{
			a[i++] = '0';
		}
		a[i] = '\0';
	}
	
	return a;
}