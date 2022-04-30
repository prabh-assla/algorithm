#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void fflushStdin(){
    char flush;

    do{
        flush = getchar();

    } while( flush != '\n' && flush != EOF );

}


typedef struct{

    int data;
    struct node *linker;

} node;


int nodeSize = sizeof( node );


node* nodeLength ( node* head, int* length ){

    node* RunTillTail = (node*) malloc( nodeSize );
    RunTillTail = head;

    while( RunTillTail -> linker != NULL ){

        RunTillTail = RunTillTail -> linker;
        ++(*length);
    }

return head;
}


node* transversalOfList ( node *head ){
    node* RunTillTail = (node*) malloc( nodeSize );
    node* OneStepLess = (node*) malloc( nodeSize );

    RunTillTail = head -> linker;
    OneStepLess = head;

    printf("head node : %6d\n", OneStepLess -> data);
    
    int index = 1;

    while( RunTillTail -> linker != NULL ){

        RunTillTail = RunTillTail -> linker;
        OneStepLess = OneStepLess -> linker;

        printf("node%d     : %6d\n", index, OneStepLess -> data);

    ++index;
    }
    
    if(OneStepLess -> linker != NULL){
    OneStepLess = OneStepLess -> linker;

    printf("tail node : %6d\n", OneStepLess -> data);
    }

return head;
}


#include "insertions.h" //INSERTION() function is available in here;
#include "deletions.h" //DELETION() function is available in here;


int main(){

    system("clear");

    node* head = (node*) malloc( nodeSize );
    node* tail = (node*) malloc( nodeSize );

    printf("head node has data : ");
    scanf("%d", &(head -> data));

    head -> linker = tail;

    printf("tail node has data : ");
    scanf("%d", &(tail -> data));

    tail -> linker = NULL;

    char choice = 'y';
    bool toQuit = false;

while( (choice == 'y' || choice == 'Y') && !toQuit ){

    system("clear");

    printf("1.) deletion\n2.) insertion\n3.) quit\n");

    fflushStdin();

    char option = getchar();

    switch(option){
        case '1' : head = DELETION(head);
                   break;


        case '2' : head = INSERTION(head);
                   break;


        case '3' : toQuit = true;
                   break;


    }
}

printf("thanks for using our linked list :) \n");

return 0;
}