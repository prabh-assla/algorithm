#include <stdio.h>
#include <string.h>

int check( char s1, char s2[] ){
printf("s1 -> %c s2 -> %s\n", s1, s2);

    for( int i=0; s2[i] != '\0'; ++i ){
        
        if( s2[i] == s1 )
        return i;

    }

return -1;

}

int LCS( char s1[], char s2[], int p, int q, int n, int * L ){
int j = 0;

printf("p-> %d q -> %d n -> %d *L -> %d\n", p, q, n, *L);
    if( n==1 )
    return check( s1[p], s2 );

    for(int i=1; i<n; ++i){

    int a = -1, b = -1;

    a = LCS( s1, s2, p+i-1, q, n-i, L );
    b = LCS( s1, s2, p+n-i, q, i, L );
printf("a-> %d b -> %d *L -> %d q -> %d\n", a, b, *L, q);
    if( a==-1 ){

        if( b!=-1 ){
        ++*L;
        q = b;
        }

    }

    else{

        if( b==-1 ){
            
            if( n==2 )
            ++*L;

            q = a;

        }

        else{

            if( n==2 ){

                 if( b>a ){
                     *L+=2;
                     q = b;
                 }

                 if( b==a ){
                     ++*L;
                     q = b;
                 }

                if( b<a )
                     q = a;
            }   
            
            else{

                 if( b>a ){
                     ++*L;
                     q = b;
                 }

                if( b<=a )
                     q = a;
            }
        }
    }

if( !(n == 11) )
return q;

if( n==11 ){
    if( *L > j )
    j = *L;

    *L = 0;
}
printf("j -> %d *L -> %d\n\n....", j, *L);
    }

return j;

}

int main(){

    char s1[] = "AGGTAB";
    char s2[] = "GXTXAYB";

    int l = strlen( s1 );

    int L = 0;

    int LCSlength = LCS( s1, s2, 0, -1, l, &L );

    printf("length of LCS is - %d\n", LCSlength);

    return 0;

}