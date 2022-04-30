#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int PrimeNumber( int newBucketSize ){

    bool isComposite = false;

    ++newBucketSize;

            while( 1 ){

            for(int i = 2; i < newBucketSize; ++i){

                if( newBucketSize%i == 0 ){
                isComposite = true;
                break;}

            }

            if( isComposite == true ){
                ++newBucketSize;
                isComposite = false;
                continue;
            }

            else
            return newBucketSize;

            }
}

int factorOfincrementInBuckets( int newBucketSize ){

    int prime = PrimeNumber( newBucketSize );

    return prime;
}

int Prime( int buckets ){

    bool isComposite = false;

    if( buckets == 2 )
    return buckets;

    else{
        --buckets;

        if( buckets == 2 )
        return buckets;

        while( buckets >= 3 ){

        for(int i = 2; i < buckets; ++i){

            if( buckets%i == 0 ){
            isComposite = true;
            break;}

        }

        if(isComposite == true ){
            --buckets;
            isComposite = false;
            continue;
        }

        else
        return buckets;
        
        }
    }
}

int key2( int buckets, int element ){

    int prime = Prime( buckets );

    return ( prime - (element%prime) );
}

typedef struct {
    int data;
    struct node* linker;
} node;

int nodeSize(){
    return sizeof( node );
}

int occupiedNoOfBuckets( node* head ){

    int occupancy = 0;

    node* ptr = (node*) malloc( nodeSize() );
    ptr = head;

    do{
        if( ptr -> data )
        ++occupancy;

        ptr = ptr -> linker;

    } while( ptr -> linker != NULL );

return occupancy;
}

node* transversal_Of_HashTable( node* head ){

    node* ptr = (node*) malloc ( nodeSize() );
    ptr = head;

    int i = 0;

    do{
        printf("bucket %d ----> %d\n", i, ptr -> data);

        ptr = ptr -> linker;

        ++i;

    } while( ptr -> linker != NULL );

return head;
}

#include "insertions.h"
#include "deletions.h"

int main(){

    system("clear");

    node* head = (node*) malloc( nodeSize() );
    head -> linker = NULL;

    int buckets = 1;

    char choice = 'y';
    bool toQuit = false;
    bool isFirstLoop = true;

while( (choice == 'y' || choice == 'Y') && !toQuit ){

    system("clear");

    printf("1.) insertion\n2.) deletion\n3.) transversal\n4.) quit\n");

    if(!isFirstLoop)
    fflushStdin();

    char option = getchar();

    switch(option){
    
        case '1' : 
            printf("to insert : ");

            int element;
            scanf("%d", &element);

            head = insertion( head, element, &buckets);
            break;


        case '2' : 
            printf("to delete : ");

            int element;
            scanf("%d", &element);

            head = deletion( head, element, &buckets);
            break;

        case '3' : 
            head = transversal( head );
            break;

        case '4' : 
            toQuit = true;
            break;

    }

if( !toQuit ){

    printf("do you want to continue : ");

    choice = getchar();
}

isFirstLoop = false;

}

printf("\nthanks for using \"HASHTABLE\" :)\n");

return 0;
}