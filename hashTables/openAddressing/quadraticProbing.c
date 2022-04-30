#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node* linker;
} node;

int nodeSize(){
    return sizeof( node );
}

node* transversal_Of_HashTable( node* head ){

    node* ptr = (node*) malloc ( nodeSize() );
    ptr = head;

    int i = 0;

    while( ptr -> linker != NULL ){

        printf("bucket %d ----> %d\n", i, ptr -> data);

        ptr = ptr -> linker;

        ++i;
    }

    printf("bucket %d ----> %d\n", i, ptr -> data);
return head;
}

node* filling_Of_linkedList( node* head, int bucketSize, int hashIndex, int element ){

    bool hashing_begins = false;

    node* ptr = (node*) malloc( nodeSize() );
    ptr = head;

    int index = 0;

    while( hashIndex != index ){

        ptr = ptr -> linker;
        ++index;

    }

    if( !(ptr -> data) )
    ptr -> data = element;

    else
    hashing_begins = true;

    if( hashing_begins ){

        int i = 1;

        while( 1 ){

        int extra = (int) i*i;
        int hashFormulaIndex = (hashIndex + extra )%bucketSize;

            while( index != hashFormulaIndex ){

                if(ptr -> linker == NULL)
                {
                ptr = head;
                index = 0;
                continue;
                }

                ptr = ptr -> linker;
                ++index;
            }

            if( !(ptr -> data) )
            {

            ptr -> data = element;
            break;

            }
        ++i;
        }
    }

return head;
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

void quadratic_probe( int input[], int size, int bucketSize ){

    node* head = (node*) malloc( nodeSize() );
    node* tail = (node*) malloc( nodeSize() );

    head -> linker = tail;
    tail -> linker = NULL;

    for(int i=1; i<=bucketSize-2; ++i)
        head = formation_Of_linkedList( head );

    for(int i=0; i<size; ++i)
        head = filling_Of_linkedList( head, bucketSize, input[i]%bucketSize, input[i] );

    head = transversal_Of_HashTable( head );
}

int main(){

    int input[] = {2, 5, 90};

    int size = sizeof( input ) / sizeof( input[0] );

    int bucketSize = (int) (1.5*size);

    quadratic_probe( input, size, bucketSize );

return 0;
}