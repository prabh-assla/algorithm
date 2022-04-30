#include <stdio.h>

void countX(int n, int inpt_arr[n]){
    int i, max, outpt_arr[n]; 

    max = inpt_arr[0];

            for(i=1; i<n; i++){
            if(inpt_arr[i] > max)
            max = inpt_arr[i];}

    int frequency[max+1];

for(i = 0; i<max+1; i++)
    frequency[i] = 0;

for(i = 0; i<n; i++)
    frequency[inpt_arr[i]]++;

for(i = 1; i<max+1; i++)
    frequency[i] += frequency[i - 1];

                for(i = 0; i<n; i++){
                outpt_arr[frequency[inpt_arr[i]] - 1] = inpt_arr[i];
                frequency[inpt_arr[i]]--;
        }
for(i=0; i<n; i++)
    inpt_arr[i] = outpt_arr[i];

}

int main(){
int arr[] = {1, 3, 0, 6, 9, 8}, n = 6, i;
    countX(n, arr);

for(i=0; i<n; i++)
    printf("%d  ", arr[i]);

return 0;
}