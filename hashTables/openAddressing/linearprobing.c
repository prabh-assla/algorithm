#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node* linker;
} node;

node* transversalOfList( node* head ){

    node* ptr = (node*) malloc( sizeof(node) );  

    ptr = head;
    printf("bucket0 ---> %d\n", ptr -> data);

    ptr = ptr -> linker;

    int i = 0;

    while( ptr -> linker != head ){
        ++i;

        printf("bucket%d ---> %d\n", i, ptr -> data);

        ptr = ptr-> linker;
    }

printf("\n");

return head;
}

node* fillingDataInList( node* head, int index, int element ){

    node* ptr = (node*) malloc( sizeof(node) );  

    bool firstRunSuccess = true;

    ptr = head;

    if(!index){
        if( !(ptr -> data) )
        ptr -> data = element;

        else
        firstRunSuccess = false;
    }

    ptr = head -> linker;
    if(index){

    int i = 1;

    while(i != index){

        ptr = ptr -> linker;
        ++i;
    }

        if( !(ptr -> data) )
        ptr -> data = element;

        else
        firstRunSuccess = false;

        ptr = ptr -> linker;

    if(ptr -> linker == head)
    ptr = head;

    }


    if(!firstRunSuccess){    

        while(1){

            if( !(ptr -> data) ){
            ptr -> data = element;
            break;}

            ptr = ptr -> linker;

        }
    }

return head;
}

node* circularLinkedList( node* head, int size ){

    node* ptr = (node*) malloc( sizeof(node) );
    node* ptr1 = (node*) malloc( sizeof(node) );
    node* ptr2 = (node*) malloc( sizeof(node) );

    ptr = head;
    ptr2 = head -> linker;
    
    ptr -> linker = ptr1;
    ptr1 -> linker = ptr2;

return head;
}

void linearProbe( int input[], int size ){

    int buckets = size;

    if( size <= 10 )
    buckets = 10;

    node* head = (node*) malloc( sizeof(node) );
    node* tail = (node*) malloc( sizeof(node) );
    head -> linker = tail;
    tail -> linker = head;

    for(int i=1; i<=buckets-1; ++i)
    head = circularLinkedList( head, size );

    for(int i=0; i<size; ++i)
    head = fillingDataInList( head, input[i]%10, input[i] );

    head = transversalOfList( head );

}

int main(){

    int input[] = {59, 29, 69, 13, 43, 60};

    int size = sizeof( input ) / sizeof( input[0] );

    linearProbe( input, size );

return 0;
}