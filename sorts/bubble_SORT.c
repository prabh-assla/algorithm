#include <stdio.h>

int main(){
    int arr[5] = {0, -4, 0, -500, 1291}, x, y, frst, scnd, *pt = &arr[0], n = 5;
    
    for(x=0; x<=n; x++){
        for(y=0; y<=n-1; y++){
            frst = *pt;
            pt++;
            scnd = *pt;
            if(frst>scnd){
                *pt = frst;
                pt--;
                *pt = scnd;
                pt++;
            }
        }
    pt-=n;
    }
    printf("\n");

for(x=0; x<=n-1; x++){
    printf("%d  ", arr[x]);
}
    printf("\n");
return 0;
}