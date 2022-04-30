#include <stdio.h>

int getmax(int size, int input[size]) {
    int max = input[0];

    for(int i = 1; i < size; ++i)
        if (input[i] > max)
            max = input[i];
    
    return max;
}

int digits_counter(int max){
    int count = 0;

    while(max!=0){
        max /= 10;
        ++count;
    }

    return count;
}

void RADIXSORT(int size, int input[size]){
    int significant_frequency_storer[10];
    int output[size];

    int max = getmax(size, input);
    int max_element_length = digits_counter(max);

    int multiplier = 1;

        for(int j=0; j<max_element_length; ++j){

            for(int i=0; i<=9; ++i)
            significant_frequency_storer[i] = 0;

            for(int i=0; i<size; ++i)
            ++significant_frequency_storer[(input[i]/multiplier)%10];

            for(int i=1; i<10; ++i)
            significant_frequency_storer[i] += significant_frequency_storer[i-1];

            for(int i = size-1; i>=0; --i){
            output[significant_frequency_storer[(input[i]/multiplier)%10] - 1] = input[i];
            significant_frequency_storer[(input[i]/multiplier)%10]--;
            }

            for(int i=0; i<size; ++i)
            input[i] = output[i];

            multiplier*=10;
        }   
}


void printARRAY(int size, int input[size]){    
        printf("\n");

        for(int i=0; i<size; ++i){
            printf("%d  ", input[i]);
        }

        printf("\n");
}

int main(){
        int input[] = {0, 2, 50, 55, 0}, size;

        size = sizeof(input) / sizeof(int);

        RADIXSORT(size, input);

        printARRAY(size, input);

return 0;
}