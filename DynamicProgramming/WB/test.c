#include <stdio.h>
#include <string.h>

void printt( char s2[][5] ){
    printf("%s%s%s%c", s2[0], s2[1], s2[2], s2[3][1]);

}

int main(){
    
char s1[] = "perfection";
char s2[][7] = {"perf", "ect", "ion", "ism", "ISSSTIC"};

printf("%d\n", sizeof( s2 )/ 7 );

printt( s2 );

return 0;

}