node* nodeLength ( node* head, int* length ){

    node* RunTillTail = (node*) malloc( nodeSize() );
    RunTillTail = head;

    while( RunTillTail -> linker != NULL ){

        RunTillTail = RunTillTail -> linker;
        ++(*length);
    }

return head;
}

node* checkisapplicableForDeletion( node* head ){
    node* step1 = (node*) malloc( nodeSize() );

    step1 = head;

    if(step1 -> linker == NULL)
    return main();

return head;
}

node* deleteTail( node* head ){    
    head = checkisapplicableForDeletion( head );

    node* toRunTillTail = (node*) malloc( nodeSize() );
    node* OneStepLess = (node*) malloc( nodeSize() );

    toRunTillTail = head -> linker;
    OneStepLess = head;

    while(toRunTillTail -> linker != NULL){
        toRunTillTail = toRunTillTail -> linker;

        OneStepLess = OneStepLess -> linker;
    }

    printf("tail data that was deleted : %d\n", toRunTillTail -> data);

    free( toRunTillTail );

    OneStepLess -> linker = NULL;
    
    return head;
}

node* deleteNode( node* head, int NodeNum ){
    head = checkisapplicableForDeletion( head );

    node* RunTillNode = ( node* ) malloc( nodeSize() );
    node* OneStepLess = ( node* ) malloc( nodeSize() );

    RunTillNode = head -> linker;
    OneStepLess = head;

    int location = 1;

    while( location != NodeNum != NULL ){
        RunTillNode = RunTillNode -> linker;

        OneStepLess = OneStepLess -> linker;

        ++location;
    }


    printf("node%d data that was deleted : %d\n", location, RunTillNode -> data);

    OneStepLess -> linker = RunTillNode -> linker;

    free( RunTillNode );


return head;
}

node* deleteHead( node* head ){
    head = checkisapplicableForDeletion( head );

    node* absorbNodeOfHead = head;

    head = head -> linker;

    printf("head data that was deleted : %d\n", absorbNodeOfHead -> data);

    free( absorbNodeOfHead );
    
return head;
}

node* deleteNodeByDataValue( node* head, int dataValue ){
    head = checkisapplicableForDeletion( head );

    bool MatchFound = false;

    node* RunTillaptValue = (node*) malloc( nodeSize() );
    node* OneStepLess = (node*) malloc( nodeSize() );

    RunTillaptValue = head -> linker;
    OneStepLess = head;

        if(OneStepLess -> data == dataValue)
        MatchFound = true;

    int nodePosition = 0;


    while(RunTillaptValue -> linker != NULL && !MatchFound){

        RunTillaptValue = RunTillaptValue -> linker;
        OneStepLess = OneStepLess -> linker;

        if(OneStepLess -> data == dataValue)
        MatchFound = true;

        ++nodePosition;
    }


    if( MatchFound ){
        int Length = 0;
        head = nodeLength( head, &Length );

        if(nodePosition == 0)
        head = deleteHead( head );

        if(nodePosition == Length)
        head = deleteTail( head );

        if(nodePosition > 0 && nodePosition < Length)
        head = deleteNode( head, nodePosition );
        
    }
    
return head;
}


node* deletingFromHashTable( node* head, int buckets, int KEY1, int element, bool* notPresent ){

    bool hashingBegins = false;

    node* ptr = (node*) malloc( nodeSize() );
    ptr = head;

    int INDEX = 0;

    while( KEY1 != INDEX ){

        ptr = ptr -> linker;
        ++INDEX;

    }

    if( element == ptr -> data )
    head = deleteNodeByDataValue( head, element );

    if( ptr -> data == 0 )
    *notPresent = true;

    else
    hashingBegins = true;

    if( hashingBegins && !notPresent ){

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

            if( element == ptr -> data )
            {

            head = deleteNodeByDataValue( head, element );
            break;

            }

            if( ptr -> data == 0 ){
            *notPresent = true;

            break;
            }

        ++i;
        }
    }

if( *notPresent )
printf("no data value present as such\n");

return head;
}

node* deletion( node* head, int element, int* buckets){

bool notPresent = false;

head = deletingFromHashTable( head, *buckets, element%(*buckets), element, &notPresent );

node* ptr = (node*) malloc( nodeSize() );
ptr = head;

if( !notPresent ){
    --(*buckets);

    int size = occupiedNoOfBuckets( head );

    for(int i = 1; i <= *buckets; ++i){

        if( ptr -> data )
        head = fillingOfHashTable( head, *buckets, (ptr->data)%(*buckets), ptr->data );

        else
        continue;
    }

}

return head;
}