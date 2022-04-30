#include <stdio.h>

void insertionSORT(float input[], int size){
    for(int i=1; i<size; i++){
    
    float being_compared = input[i];
    int j;

        for(j=i-1; j>=0; j--){
        float compared_WITH = input[j];

        if(being_compared < compared_WITH)
        input[j+1] = compared_WITH;

        else
        break;}
    
    input[j+1] = being_compared;

    j=0;}

}

void bucketSORT(float input[], int size, int multiplier, int DIVISIONS){
    
    typedef struct sorter{
        float buckets[size];
    } sorter;

    sorter division_of_input[DIVISIONS];

    for(int i=0; i<DIVISIONS; i++)
    for(int j=0; j<size; j++)
    division_of_input[i].buckets[j] = 0;

    for(int i=0; i<size; i++){
        int j = 0;

        int index = multiplier*input[i];

        while(division_of_input[index].buckets[j] != 0)
        j++;

        division_of_input[index].buckets[j] = input[i];}

    for(int i=0; i<DIVISIONS; i++)
    insertionSORT(division_of_input[i].buckets, size);

    int z = -1;
    
    for(int i=0; i<DIVISIONS; i++)
    for(int j=0; j<size; j++){
        if(division_of_input[i].buckets[j] != 0)
        input[++z] = division_of_input[i].buckets[j];
    }

}

void array_PRINT(float input[], int size){
    printf("\n");

    for(int i=0; i<size; i++)
        printf("%8.6f  ", input[i]);

    printf("\n");
}

int main(){
    float input[] = {0.12, 0.003, 0.133, 0.511, 0.45, 0.187, 0.1211};

    int size = sizeof(input) / sizeof(float);

    bucketSORT(input, size, 10, 10);

    array_PRINT(input, size);
return 0;
}