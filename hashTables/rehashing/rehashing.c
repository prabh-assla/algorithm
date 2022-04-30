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

    while( ptr -> linker != NULL ){

        printf("bucket %d ----> %d\n", i, ptr -> data);

        ptr = ptr -> linker;

        ++i;
    }

    printf("bucket %d ----> %d\n", i, ptr -> data);
return head;
}

node* deletingFromHashTable( node* head, int buckets, int KEY1, int element ){

    bool hashingBegins = false;

    node* ptr = (node*) malloc( nodeSize() );
    node* ptr1 = (node*) malloc( nodeSize() );

    ptr = head;
    ptr1 = head -> linker;

    if( KEY1 == 0 ){

    int INDEX = 0;
    if( ptr -> data == element ){

        head = ptr1;
        free( ptr );

    }

    else
    hashingBegins = true;
    }

    else{

    int INDEX = 1;

    while( KEY1 != INDEX ){

        ptr1 = ptr1 -> linker;
        ptr = ptr -> linker;
        ++INDEX;

    }

    if( ptr1 -> data == element ){
        
        ptr -> linker = ptr1 -> linker;
        
        free( ptr1 );

    }

    else
    hashingBegins = true;
    }

    if( hashingBegins ){

        int i = 1;
        int KEY2 = key2( buckets, element );

        while( 1 ){

        int extra = (i * KEY2);

        int HashFormulaIndex = (KEY1 + extra )%buckets;

            while( INDEX != HashFormulaIndex ){

                if(ptr1 -> linker == NULL)
                {
                
                ptr = head;
                ptr1 = head -> linker;
                INDEX = 0;

                continue;
                }

                ptr = ptr -> linker;
                ptr1 = ptr1 -> linker;
                ++INDEX;

            }

            if( INDEX == 0 ){

                    if( ptr -> data == element ){

                    head = ptr1;
                    free( ptr );
                    break ;
                    }
            }

            else{

                    if( ptr1 -> data == element ){

                    ptr -> linker = ptr1 -> linker;

                    free( ptr1 );

                    }
            }
        ++i;
        }
    }

return head;
}

node* fillingOfHashTable( node* head, int buckets, int KEY1, int element ){

    bool hashingBegins = false;

    node* ptr = (node*) malloc( nodeSize() );
    ptr = head;

    int INDEX = 0;

    while( KEY1 != INDEX ){

        ptr = ptr -> linker;
        ++INDEX;

    }

    if( !(ptr -> data) )
    ptr -> data = element;

    else
    hashingBegins = true;

    if( hashingBegins ){

        int i = 1;
        int KEY2 = key2( buckets, element );

        while( 1 ){

        int extra = (i * KEY2);

        int HashFormulaIndex = (KEY1 + extra )%buckets;

            while( INDEX != HashFormulaIndex ){

                if(ptr -> linker == NULL)
                {
                ptr = head;
                INDEX = 0;
                continue;
                }

                ptr = ptr -> linker;
                ++INDEX;
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

node* additionOfBuckets( node* head ){

    node* ptr = (node*) malloc( nodeSize() );
    node* ptr1 = (node*) malloc( nodeSize() );
    node* ptr2 = (node*) malloc( nodeSize() );

    ptr = head;
    ptr2 = head -> linker;

    ptr -> linker = ptr1;
    ptr1 -> linker = ptr2;

return head;
}

node* deletion( node* head, int element, int* buckets ){

    head = deletingFromHashTable( head, *buckets, element%buckets, element  );

}

node* insertion( node* head, int element, int* buckets ){
    
    bool primaryCase = false;

    int factor = 3;
    int occupiedBuckets = 1;

    if( *buckets == 1 )
    primaryCase = true;

    if( primaryCase ){
        node* tail = (node*) malloc( nodeSize() );
        node* mid = (node*) malloc( nodeSize() );

        head -> linker = mid;
        mid -> linker = tail;
        tail -> linker = NULL;

    }

    if( !primaryCase ){
    occupiedBuckets = occupiedNoOfBuckets( head );

    int loadFactor = occupiedBuckets / *buckets;

    if( loadFactor > 1 ){

        factor = factorOfincrementInBuckets( 2*(*buckets) );

        for( int i = *buckets; i < factor; ++i )
        head = additionOfBuckets( head );

    }
    }

    head = fillingOfHashTable( head, *buckets, element%factor, element );

return head;
}

int main(){

    node* head = (node*) malloc( nodeSize() );
    node* tail = (node*) malloc( nodeSize() );

    head -> linker = NULL;

    int buckets = 1;
    int element;

    head = insertion( head, element, &buckets);

    head = deletion( head, element, &buckets );

return 0;
}