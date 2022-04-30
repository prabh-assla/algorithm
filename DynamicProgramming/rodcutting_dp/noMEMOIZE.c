#include <stdio.h>
#include <limits.h>

int cutrod( int p[], int n, int q ){

    if( n==1 )
    return q;

    int N = 0;

        if( n%2 == 0 )
        N = n/2;

        else
        N = (n-1)/2;

        int a = 0, b = 0;

    for(int i=1; i<=N; ++i){

        if( q < ( p[i-1]+p[n-i-1] ) )
        q = ( p[i-1]+p[n-i-1] );

    a = p[i-1];
    b = p[n-i-1];
            
            if( cutrod( p, i, p[i-1] ) > a )
            a =  cutrod( p, i, a );

            if( cutrod( p, n-i, p[n-i-1] ) > b )
            b =  cutrod( p, n-i, b );

    if( a+b > q )
    q = a + b;

    }

return q;

}

int main(){

    int p[] = {1, 3, 4, 5, 7, 1, 2, 6};

    int n = sizeof( p )/sizeof( p[0] );

    int maxPROFIT = cutrod( p, n, p[n-1] );

    printf("thus, max profit we can obtain is - %d\n", maxPROFIT);

    return 0;

}