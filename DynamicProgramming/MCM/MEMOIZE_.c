#include <stdio.h>
#include <limits.h>

int check( int a, int b, int c, int d ){

    if( ( a*b*c + a*c*d ) < ( a*b*d + b*c*d ) )
    return ( a*b*c + a*c*d );

    else
    return ( a*b*d + b*c*d );

}

int MCM( int a[], int q, int n ){
    if( n-q+1 == 2 || n-q+1 == 1 )
    return 0;

    int N = (n-q+1)/2;

    if( n%2 != 0 )
    ++N;


    int sum = 0;

    int temp = INT_MAX;

    for( int i=1; i<N; ++i ){

        int x = MCM( a, q, n-2*i );
        int y = MCM( a, n-2*i+1, n );

        int value = check( a[q-1], a[n-2*i-1], a[n-2*i], a[n-1] );

        sum += x + y + value;

        if( (n-q+1) == 3 ){

            if( sum < temp )
            temp = sum;

            sum = 0;
        }

    }
    
if( (n-q+1) == 3 )
return temp;

return sum;
                         
}

int main(){

    int a[] = {1, 6, 9};
    int n = sizeof( a )/sizeof( a[0] );

    int minCOST = MCM( a, 1, n );

    printf("thus, minimum cost for MCM is - %d\n", minCOST);

return 0;
}