#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node* linker_to_next; //a pointer pointing to "node" itself
} node;

void linkedlist_TransversaL(node *pointer){
    while(pointer != NULL){
        printf("%d  ", pointer->data);
        pointer = pointer->linker_to_next;
    }
}

int main(){
    int node_size = sizeof(node);

    node* n[5]; //5 node pointers have been created
    
    n[0] = (node *) malloc(node_size);
    n[1] = (node *) malloc(node_size);
    n[2] = (node *) malloc(node_size);
    n[3] = (node *) malloc(node_size);
    n[4] = (node *) malloc(node_size);

    //link first and second node -->
    n[0] -> data = 10;
    n[0] -> linker_to_next = n[1];

    //link second and third node -->
    n[1] -> data = 20;
    n[1] -> linker_to_next = n[2];

    //link third and fourth node -->
    n[2] -> data = 30;
    n[2] -> linker_to_next = n[3];

    //link fourth and fifth node -->
    n[3] -> data = 40;
    n[3] -> linker_to_next = n[4];

    //link fifth and sixth node -->
    n[4] -> data = 50;
    n[4] -> linker_to_next = NULL; 

    linkedlist_TransversaL(n[0]);

return 0;
}