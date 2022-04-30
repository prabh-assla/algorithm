
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

        node* ptr = (node*) malloc( nodeSize() );
        ptr = head;
        
        /////pehle array banao usme sabh values dalo, fir linkedlist ko zero karo, fir us
        /////array say values link list mein utaro

        for( int i = 1; i <= factor; ++i){

        if( ptr -> data )
        head = fillingOfHashTable( head, factor, (ptr->data)%factor, ptr->data );

        else
        continue;

        }

    }

}

    head = fillingOfHashTable( head, *buckets, element%factor, element );

return head;
}