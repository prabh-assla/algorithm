#include <stdio.h>

    int horner(char *pt, int i){
        int coeff = 1, COEF = 0;
        char flag = 'n';

        while(*pt != 0){
            while(*pt!=120 && *pt!=0){
            if(*pt == 45)
                coeff*=-1;
            if(*pt == 43)
                coeff*=1;
            if(*pt<=57 && *pt>=48)
                coeff*=(*pt-48);
            pt++;}
            
if(flag == 'y'){
    COEF *= i;
    COEF += coeff;
}
else{
    flag = 'y';
    COEF = coeff;
}

            while(*pt!=45 && *pt!=43 && *pt!=0)
                pt++;
coeff = 1;
}
return COEF;}

int main(){
char str[] = "2x^4 -x^3 +3x^2 +x -5";
int i, j;
        printf("type value of x : ");
        scanf("%d", &i);
    j = horner(str, i);

printf("thus, req. val is : %d\n" ,j);
return 0;
}