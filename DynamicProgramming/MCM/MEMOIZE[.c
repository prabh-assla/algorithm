#include <stdio.h>

int costCALC( int p[], int i, int a, int b, int c, int d ){

    int s = 0;

    if( ( a*b*c + a*c*d ) < ( a*b*d + b*c*d ) )
    s = ( a*b*c + a*c*d );

    else
    s = ( a*b*d + b*c*d );

    p[i+2] = p[0];

return s;

}

int MCM( int p[], int n, int q, int sum ){

        while( q+3 < n ){

            sum += costCALC( p, q, p[q], p[q+1], p[q+2], p[q+3] );
            q += 2;
        }

        if( q+3 == n )
        sum += ( p[q]*p[q+1]*p[q+2] );

        if( q+2 == n && !sum )
        sum += ( p[q]*p[q+1] );

        if( q+1 == n && !sum )
        printf("no valid matrix possible\n");

return sum;

}

int main(){

    int p[] = {6, 9, 1, 9, 7, 3};

    int n = sizeof( p )/sizeof( p[0] );

    int sum = 0;
    
    int minCOST = MCM( p, n, 0, sum);

    if( minCOST )
    printf("thus, min cost we can obtain is - %d\n", minCOST);

    return 0;

}