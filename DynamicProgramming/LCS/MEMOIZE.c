#include <stdio.h>

// static int m[ 20 ];

int check( char e, char* ptr ){

int i = 0;

    while( *ptr != '\0' ){
        
    ++i;
        
        if(*ptr == e)
        return i;

    ++ptr;

    }

return 0;

}

int LCSlen( char s1[], char s2[], int q, int n, int* l ){

    if( n==1 )
    return check( s1[q], s2 );

    // if( m[n-1] != 0 )
    // return m[n-1];

    int a = 0, b = 0;

    for(int i=1; i<n; ++i){

    a = LCSlen( s1, s2, q+i-1, n-i, l );
    b = LCSlen( s1, s2, q+n-i, i, l );

        if( a ){

            if( b>a ){
            *l+=2;
            return b;}

            else{
            ++*l;
            return a;}


        }

        if( !a ){

            if( b )
            ++*l;

        return b;
    
        }

    // if( a+b > q ){
    // q = a + b;
    // m[n-1] = q;}

    }
}

int main(){

    char s1[] = "aditoy";
    char s2[] = "ao";

    int l1 = sizeof( s1 )/sizeof( s1[0] );

    int LCSlength = 0;

    LCSlength = LCSlen( s1, s2, 0, l1-1, &LCSlength );

    printf("length of LCS is - %d\n", LCSlength);

    return 0;

}