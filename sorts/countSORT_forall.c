#include <stdio.h>

int GAIN_max(int n, int input_array[n]){
    int max = input_array[0];
    for(int i=1; i<n; i++){
        if(input_array[i] > max)
        max = input_array[i];
    }
return max;
}

int GAIN_num_of_neg(int n, int input_array[n]){
    int neg_numbers_count = 0;
    for(int i=0; i<n; i++){
        if(input_array[i] < 0)
        neg_numbers_count++;
    }
return neg_numbers_count;
}

void countsort(int n, int input_arr[n], char flag){
    int i;

    int max = GAIN_max(n, input_arr);
    int num_of_neg = GAIN_num_of_neg(n, input_arr);

    int frequency_of_occurance[max+1];

    for(i=0; i<max+1; i++)
    frequency_of_occurance[i] = 0;

    for(i=0; i<n; i++){
    if(input_arr[i]>=0)
    frequency_of_occurance[input_arr[i]]++;
    }

    for(i=1; i<max+1; i++)
    frequency_of_occurance[i] += frequency_of_occurance[i-1];

                int outpt_arr[n];

                for(i = 0; i<n; i++){
                if(input_arr[i]>=0)
                {
                outpt_arr[num_of_neg + frequency_of_occurance[input_arr[i]] - 1] = input_arr[i];
                frequency_of_occurance[input_arr[i]]--;
                }
                }

if(flag == 'y'){
for(i=0; i<n; i++)
input_arr[n-i-1] = -1*outpt_arr[i];
}

if(flag == 'n'){
int k = 0;
        for(i=0; i<n; i++)
        {
        if(input_arr[i]<0){
        outpt_arr[k] = -1*input_arr[i];
        k++;
        }
        }
        countsort(num_of_neg, outpt_arr, 'y');

for(i=0; i<n; i++)
input_arr[i] = outpt_arr[i];
}
}

void print_array(int n, int input_array[n]){
int j;

printf("\n");

for(j=0; j<n; j++)
printf("%d  ", input_array[j]);

printf("\n");
}

int main(){
int input_array[] = {-1, 0, -110, 0, -1, 7890, 5444, 0};

int total_num_of_elements = sizeof(input_array)/sizeof(int);

    countsort(total_num_of_elements, input_array, 'n');

    print_array(total_num_of_elements, input_array);

return 0;
}