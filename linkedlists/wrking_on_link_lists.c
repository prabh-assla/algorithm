#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node* linker;
} node;

void linkedlist_TransversaL(node *pointer){
    while(pointer != NULL){
        printf("%d  ", pointer->data);
        pointer = pointer->linker;
    }
}

int main(){
    node* n[7];

    int nodeSize = sizeof(node);

    int nodesNumber = sizeof(n) / sizeof(n[0]);

    for(int i=0; i<nodesNumber; i++)
        n[i] = (node *) malloc(nodeSize);

    for(int i=0; i<nodesNumber; i++){
        printf("data%d : ", i+1);
        scanf("%d", &(n[i]->data));
        n[i] -> linker = n[i+1];
    }

    n[nodesNumber-1] -> linker = NULL;

    linkedlist_TransversaL(n[0]);

return 0;
}