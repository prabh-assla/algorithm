#include <stdio.h>

int kadane(int *ptr, int indx_last){
    int i, j, arr[indx_last+1], num[indx_last+1], max, sum;

num[0] = *ptr;
max = num[0];


    for(i=1; i<=indx_last; i++){
            ptr++;
            if(*ptr+num[i-1] > *ptr)
                num[i] = *ptr+num[i-1];
            else
            num[i] = *ptr;
    }
    ptr-=indx_last;

    for(i=1; i<=indx_last; i++){
        if(num[i] > max){
            max = num[i];
            j = i;}
    }

    sum = max;
printf("\nthe sub-array is :\n");
while(sum != 0){
    ptr+=j;
    printf("%d ", *ptr);
    sum-=(*ptr);
    ptr-=j;
    j--;
    }
printf("\n");
return max;
}

int main(){
    int arr[3] = {-1, -1, 3}, sum, i;

sum = kadane(arr, 2);

    printf("max. sub-array sum is -> %d\n", sum);

return 0;
}