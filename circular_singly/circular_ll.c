#include <stdio.h>

typedef struct {
    int data;
    struct node* linker;
} node;

int main(){

    node* head = (node*) malloc( sizeof(node) );
    node* tail = (node*) malloc( sizeof(node) );

    head -> data = 1;
    head -> linker = tail;
    tail -> data = 2;
    tail -> linker = head;

    node* ptr = head;

    for(int i = 0; i < 3; ++i){

    printf("\n");

        while( ptr -> linker != head ){
        printf("%d ", ptr -> data);
        ptr = ptr -> linker;}

        printf("%d ", ptr -> data);
        ptr = ptr -> linker;

    printf("\n");}

return 0;
}