#include <stdio.h>
#include <string.h>

int check( const int size, char s2[][size], char s, const int L, int * q, int * r ){

    for( int i=0; i<=L-1; ++i ){
         for( int j=0; s2[i][j] != '\0', ++j ){

             if( s2[i][j] == s ){
                 *q = i;
                 *r = j;
                 return 1;
             }
         }
    }

return 0;

}

int WB( const int size, char s2[][size], char s1[], int l, const int L, int * q, int * r ){

    if( l==1 )
    return check( size, s2, s1[q], L, q, r );

    
}

int main(){

    char s1[] = "perfection";
    int l = strlen( s1 );

    const int size = 8; 
    char s2[][size] = {"perf", "ect", "ion"};
    int L = sizeof( s2 ) / size;

    int q = 0;
    int r = 0;

    int possible = WB( size, s2, s1, l, L, &q, &r );

    if( !possible )
        printf("no such words available that can conjoin\n");

    else
        printf("yes it is possible indeed\n");

return 0;

}