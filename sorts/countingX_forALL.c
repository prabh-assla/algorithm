#include <stdio.h>

void countX(int n, int inpt_arr[n], char time){
    int i, max, push=0;

    max = inpt_arr[0];
        for(i=0; i<n; i++){
        if(inpt_arr[i] > max)
        max = inpt_arr[i];

        if(inpt_arr[i]<0)
        push++;
}

    int frequency[max+1];

for(i = 0; i<max+1; i++)
    frequency[i] = 0;

for(i = 0; i<n; i++){
    if(inpt_arr[i]>=0)
    frequency[inpt_arr[i]]++;}

for(i = 1; i<max+1; i++)
    frequency[i] += frequency[i - 1];

int outpt_arr[n-push];
                for(i = 0; i<n; i++){
                    if(inpt_arr[i]>=0){
                outpt_arr[frequency[inpt_arr[i]] - 1] = inpt_arr[i];
                frequency[inpt_arr[i]]--;}
}

if(time == '1'){
    int j;
            for(i=0; i<n; i++)
                inpt_arr[n-i-1] = -1*outpt_arr[i];
}

if(time == '0'){
int arr[push], k;
    for(i=0; i<n; i++){
        if(inpt_arr[i]<0){
    arr[k] = -1*inpt_arr[i];
    k++;}
    }
    countX(push, arr, '1');

for(i=0; i<push; i++)
    inpt_arr[i] = arr[i];
for(i=push; i<n; i++)
    inpt_arr[i] = outpt_arr[i-push];
}
}

int main(){
int arr[] = {-87, -87, 10000, 100000, 0, -1, -33, 800, -87, -8}, n = 10, i;
    countX(n, arr, '0');

printf("\n");
for(i=0; i<n; i++)
    printf("%d  ", arr[i]);
printf("\n");

return 0;
}