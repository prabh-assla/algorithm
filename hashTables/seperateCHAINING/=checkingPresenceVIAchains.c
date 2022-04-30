#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {

    int data;
    struct node* linker;
} node;

node* printfying( node* head, int bucket ){

    node* ptr = (node*) malloc( sizeof(node) );
    ptr = head;

    printf("bucket%d --> ", bucket);

    while(ptr -> linker != NULL){

        printf("%d ", ptr -> data);
        ptr = ptr -> linker;}

    printf("\n");

return head;
}

node* hashtable( node* head, int element ){
    
    node* ptr1 = (node*) malloc( sizeof(node) );
    node* ptr2 = (node*) malloc( sizeof(node) );

    ptr1 = head;

    int sum = 0;

    while( ptr1 -> linker != NULL){

        ++sum;
        ptr1 = ptr1 -> linker;
    }

    ptr1 -> data = element;
    ptr1 -> linker = ptr2;
    ptr2 -> linker = NULL;

return head;
}

node* initializer( node* head ){

        head = (node*) malloc( sizeof(node) );
        head -> linker = NULL;

return head;
}

int linklistSize( int input[], int size ){

    int max = input[0]%10;

    for(int i=1; i<size; ++i){

        if(input[i]%10 > max)
        max = input[i]%10;

    }

return ++max;
}

void hashsort(int input[], int size){

    int numOflinkedlists = linklistSize( input, size );
    node* n[numOflinkedlists];

    for(int i=0; i<size; ++i)
        n[i] = initializer( n[i] );

    for(int i=0; i<size; ++i)
        n[ input[i]%10 ] = hashtable( n[input[i]%10], input[i] );

    system( "clear" );

    for(int i=0; i<numOflinkedlists; ++i)
        n[i] = printfying( n[i], i );

}

int main(){
    int input[] = {11, 13, 21, 45, 55, 60, 22, 19, 18, 76, 77, 86, 49, 10, 91, 33, 37, 51, 66, 80};
    
    int size = sizeof( input ) / sizeof( input[0] );

    hashsort( input, size );

return 0;
}