#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void fflush_Stdin(){
    char ch;

    do{
        ch = getchar();
    } while( ch != '\n' && ch != EOF );

}

typedef struct {
    int data;
    struct node* linker;
} node;

int nodeSize(){
    return sizeof( node );
}

node* formation_Of_linkedList( node* head ){

    node* ptr = (node*) malloc( nodeSize() );
    node* ptr1 = (node*) malloc( nodeSize() );
    node* ptr2 = (node*) malloc( nodeSize() );

    ptr = head;
    ptr2 = head -> linker;

    ptr -> linker = ptr1;
    ptr1 -> linker = ptr2;

return head;
}

int main(){

        for(int i=1; i<=bucketSize-2; ++i)
        head = formation_Of_linkedList( head );
    
    char choice = 'y';
    bool toQuit = false;
    bool isitFirstLoop = true;

    while( (choice == 'y' || choice == 'Y') && !toQuit ){
        
        system( "clear" );

        printf("1.) insertion\n2.) deletion\n3.) searching\n4.) quit");

        fflush_stdin();
        char option = getchar();

        switch( option ){

            case '1' :
            printf("datavalue to insert : ");

            int data;
            scanf("%d", &data);

            head = insertion( head, data, size );
        }
    }

return 0;
}