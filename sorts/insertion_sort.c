#include <stdio.h>
int main(){

int arr[6] = {-5, 6, 12, -123, 0, 0}, x, y, key, flag, sum = 0, sum1 = 0, *pt = &arr[0];
pt++;

for(x=1; x<6; x++){
    key = *pt;
    pt--;
        for(y=1; y<=x; y++){
            flag = *pt;
            if (key>flag){
                pt++;
                *pt = flag;
                sum++;
            }
            else{
                pt++;
                sum1++;
                break;}
        if(y!=x)
        pt-=2;
        else
        pt--;
        }
    *pt = key;
    if(sum1 != 0)
    pt+=sum+sum1;
    else
    pt+=sum+sum1+1;
    sum = 0;
    sum1 = 0;
    }

for(x=0; x<6; x++){
    printf("\n%d ", arr[x]);
}

printf("\n");

return 0;
}