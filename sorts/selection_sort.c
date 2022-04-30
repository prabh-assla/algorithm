#include <stdio.h>
int main(){
int arr[3] = {-10900, -203, -1098}, x, y, z, *pt = &arr[0], key, flag, sum = 0;

    for(x=2; x>0; x--){
        key = *pt;
            for(y=0; y<=x; y++){
                if(key>*pt){
                    flag = *pt;
                    *pt = key;
                    pt-=sum;
                    *pt = flag;
                    pt++;
                    break;
                }
                else
                sum++;
                pt++;
            }
            if(sum==x+1){
                pt-=x;
            }
        sum = 0;

    }

    for(z=0; z<=2; z++){
        printf("%d\n", arr[z]);
    }

return 0;
}