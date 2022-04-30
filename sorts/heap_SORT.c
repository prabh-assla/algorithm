#include <stdio.h>

void swap(int*i, int*j){
    int k = *i;
    *i = *j;
    *j = k;
}

void building_MAX_heap(int input[], int size, int parent){
    int initial_parent_position = parent;

    int left_child = 2*parent+1;
    int right_child = 2*parent+2;

    if(left_child <= size-1 && input[left_child] > input[parent])
    parent = left_child;

    if(right_child <= size-1 && input[right_child] > input[parent])
    parent = right_child;

    if(parent != initial_parent_position){
        swap(&input[parent], &input[initial_parent_position]);

        building_MAX_heap(input, size, parent);
    }
}

void HEAPSORT(int input[], int size){
    int middle_of_input = size/2-1;
    int zeroth_index = 0;

    for(int parent = middle_of_input; parent>=zeroth_index; --parent)
        building_MAX_heap(input, size, parent);

    int index_1plus_to_zeroth = 1;
    int index_of_last_element = size-1;

    for(int size_being_sent_for_finalizing_MAXHEAP = index_of_last_element; 
    size_being_sent_for_finalizing_MAXHEAP >= index_1plus_to_zeroth; 
    --size_being_sent_for_finalizing_MAXHEAP){

        swap(&input[0], &input[size_being_sent_for_finalizing_MAXHEAP]);

        building_MAX_heap(input, size_being_sent_for_finalizing_MAXHEAP, zeroth_index);
}

}

void print_ARRAY(int input[], int size){
    printf("\n");

    for(int i=0; i<size; i++){
        printf("%d  ", input[i]);
    }

    printf("\n");
}

int main(){
    int input[] = {0, 0, 4, -3, -23, -4, -4, 67, 545355, -6666666, 0};

    int size = sizeof(input) / sizeof(int);

    HEAPSORT(input, size);

    print_ARRAY(input, size);

    return 0;
}