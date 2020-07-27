#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE	255
int
BF_index( char *s1, char *s2 );

void
KMP_getNext( char *s2, int *next );

int
KMP_index( char *s1, char *s2 );

void
KMP_getNextval( char *s2, int *nextval );

int
main( int argc, char **argv )
{
	int i;
	int next[MAXSIZE];
	KMP_getNextval("aaaaax", next);
	for( i = 0; i < 6; i++ ){
		printf("%d ", next[i]);
	}
	return 0;
}

int
BF_index( char *s1, char *s2 )
{
	int i = 0, j = 0;
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);
	while( i < s1_len  && j < s2_len ){
		printf("i = %d, j = %d\n", i, j );
		if( s1[i] == s2[j] ){
			i++;
			j++;
		}else{
			i = i - j + 1;
			j = 0;
		}
	}
	if( j >= s2_len ){
		return ( i - s1_len );
	}else{
		return -1;
	}
}

void
KMP_getNext( char *s2, int *next )
{
	int j = 0, k = -1;
	next[0] = -1;
	while( j < strlen(s2) - 1 ){
		if( k == -1 || s2[j] == s2[k] ){
			j++;
			k++;
			next[j] = k;
		}else{
			k = next[k];
		}
	}
}

int
KMP_index( char *s1, char *s2 )
{
	int i = 0, j = 0;
	int next[MAXSIZE];
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);
	
	KMP_getNext( s1, next );
	while( i < s1_len && j < s2_len ){
		printf("i = %d, j = %d\n", i, j );
		if( j == -1 || s1[i] == s2[j] ){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}
	if( j >= s2_len ){
		return ( i - s2_len );
	}else{
		return -1;
	}
}

void
KMP_getNextval( char *s2, int *nextval )
{
	int j = 0, k = -1;
	nextval[0] = -1;
	while( j < strlen(s2) - 1 ){
		if( k == -1 || s2[j] == s2[k] ){
			j++;
			k++;
			if( s2[j] != s2[k] ){
				nextval[j] = k;
			}else{
				nextval[j] = nextval[k];
			}
		}else{
			k = nextval[k];
		}
	}
}