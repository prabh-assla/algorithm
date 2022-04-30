#include <stdio.h>
#include <limits.h>

int check( int a, int b, int c, int d ){

    if( ( a*b*c + a*c*d ) < ( a*b*d + b*c*d ) )
    return ( a*b*c + a*c*d );

    else
    return ( a*b*d + b*c*d );

}

int MCM( int a[], int q, int n, const int N ){
    if( n-q+1 == 1 || n-q+1 == 2 )
    return 0;

    int sum = 0;

    int value = 0;

    int temp = INT_MAX;

    for( int i=1; i<n; ++i ){

        int x = MCM( a, q, n-i, N );
        int y = MCM( a, n-i+1, n, N );

        if( !( (n-q+1) <= 3 ) )
        value = check( a[q-1], a[n-i-2], a[n-i-1], a[n-1] );

        sum += x + y + value;

        if( (n-q+1) == N){

            if( sum < temp )
            temp = sum;

            sum = 0;
        }

    }
    
if( (n-q+1) == 5 )
return temp;

return sum;
                         
}

int main(){

    int a[] = {1, 6, 3, 1, 9};
    int n = sizeof( a )/sizeof( a[0] );

    int minCOST = MCM( a, 1, n, n );

    printf("thus, minimum cost for MCM is - %d\n", minCOST);

return 0;
}