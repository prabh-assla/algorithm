#include <stdio.h>

void mergerrr(int *pt, int lw, int mid, int hgh){
        int arr[hgh+1], i=lw, j=mid+1, k=0;
    while(i<=mid && j<=hgh){
        if(*(pt+i)<=*(pt+j))
            {arr[k] = *(pt+i);
            i++;}
        else
            {
                arr[k] = *(pt+j);
                j++;
            }
    k++;
    }
                while(i<=mid){
                    arr[k] = *(pt+i);
                    i++;
                    k++;
                }

                while(j<=hgh){
                    arr[k] = *(pt+j);
                    j++;
                    k++;
                }
j = 0;
    for(i=lw; i<=hgh; i++){
        *(pt+i) = arr[j];
    j++;
    }
}

void mergeX(int *pt, int lw, int hgh){
         if(lw<hgh){
         int mid = lw + (hgh-lw)/2;
         mergeX(pt, lw, mid);
         mergeX(pt, mid+1, hgh);
         mergerrr(pt, lw, mid, hgh);
    }
}

int main(){
int arr[12] = {-123, 0, 9999, 34, -19282, 7, 8, 9, 0, 11111, 3, 66213}, n = 12;
    mergeX(arr, 0, n-1);

    for(int i=1; i<=n; i++){
        printf("%d ", arr[i-1]);
    }
printf("\n");
return 0;
}