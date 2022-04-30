#include <stdio.h>
#include <limits.h>  vb                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        

int MCM( int p[], int q, int n ){

	if( q == n )
	return 0;

	int i = 0;
	int min = INT_MAX;
	int count = 0;

	for( i = q; i < n; ++i ){

		count = MCM(p, q, i) + MCM(p, i + 1, n) + ( p[q - 1] * p[i] * p[n] );

        if (count < min)
        min = count;
    
	}

	return min;

}

int main(){

    int p[] = {1, 2, 3, 4, 5, 6, 7, 8};

	int n = sizeof( p ) / sizeof( p[0] );

	printf( "min cost of multiplications - %d\n", MCM(p, 1, n - 1) );

	return 0;

}