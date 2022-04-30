#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int Prime( int bucketSize ){

    bool isComposite = false;

    if( bucketSize == 2 )
    return bucketSize;

    else{
        --bucketSize;

        if( bucketSize == 2 )
        return bucketSize;

        while( bucketSize >= 3 ){

        for(int i = 2; i < bucketSize; ++i){

            if( bucketSize%i == 0 ){
            isComposite = true;
            break;}

        }

        if(isComposite == true ){
            --bucketSize;
            isComposite = false;
            continue;
        }

        else
        return bucketSize;
        
        }
    }
}

int key2( int bucketSize, int element ){

    int prime = Prime( bucketSize );

    return ( prime - (element%prime) );
}

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

node* filling_Of_linkedList( node* head, int bucketSize, int key1, int element ){

    bool hashing_begins = false;

    node* ptr = (node*) malloc( nodeSize() );
    ptr = head;

    int hashIndex = 0;

    while( key1 != hashIndex ){

        ptr = ptr -> linker;
        ++hashIndex;

    }

    if( !(ptr -> data) )
    ptr -> data = element;

    else
    hashing_begins = true;

    if( hashing_begins ){

        int i = 1;
        int Key2 = key2( bucketSize, element );

        while( 1 ){

        int extra = (i * Key2);

        int hashFormulaIndex = (key1 + extra )%bucketSize;

            while( hashIndex != hashFormulaIndex ){

                if(ptr -> linker == NULL)
                {
                ptr = head;
                hashIndex = 0;
                continue;
                }

                ptr = ptr -> linker;
                ++hashIndex;
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

void double_hashing( int input[], int size, int bucketSize ){

    node* head = (node*) malloc( nodeSize() );
    node* tail = (node*) malloc( nodeSize() );

    head -> linker = tail;
    tail -> linker = NULL;

    if( bucketSize == 1 ){

        head -> linker = NULL;
        free( tail );

    }

    for(int i=1; i<=bucketSize-2; ++i)
        head = formation_Of_linkedList( head );

    for(int i=0; i<size; ++i)
        head = filling_Of_linkedList( head, bucketSize, input[i]%bucketSize, input[i] );

    head = transversal_Of_HashTable( head );
}

int main(){

    int input[] = {17, 9, 26, 44, 27, 35, 18};

    int size = sizeof( input ) / sizeof( input[0] );

    int bucketSize = (int) (1.3*size);

    double_hashing( input, size, bucketSize );

return 0;
}