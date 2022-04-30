

node* checkisapplicableForDeletion( node* head ){
    node* step1 = (node*) malloc( nodeSize );

    step1 = head -> linker;


    if(step1 -> linker == NULL)
    return main();

return head;
}



node* deleteTail( node* head ){    
    head = checkisapplicableForDeletion( head );

    node* toRunTillTail = (node*) malloc( nodeSize );
    node* OneStepLess = (node*) malloc( nodeSize );

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

    node* RunTillNode = ( node* ) malloc( nodeSize );
    node* OneStepLess = ( node* ) malloc( nodeSize );

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

    node* RunTillaptValue = (node*) malloc( nodeSize );
    node* OneStepLess = (node*) malloc( nodeSize );

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


    if(MatchFound){
        int Length = 0;
        head = nodeLength( head, &Length );

        if(nodePosition == 0)
        head = deleteHead( head );

        if(nodePosition == Length)
        head = deleteTail( head );

        if(nodePosition > 0 && nodePosition < Length)
        head = deleteNode( head, nodePosition );
        
    }


    else
    printf("data value is absent\n");
    
return head;
}



node* DELETION(node* head){

    char choice = 'y';
    bool toQuit = false;


while((choice == 'y' || choice == 'Y') && !toQuit){
    printf("");

    system("clear");

    printf("1.) delete head\n2.) delete node in between\n3.) delete node||head||tail via value\n4.) delete tail\n5.) transversal of list\n6.) quit\n");

        fflushStdin();

    char option = getchar();

    switch( option ){

        case '1' : head = deleteHead( head );

                   break;


        case '2' :  printf("node number to delete : ");

                    int NodeNum;

                    scanf("%d", &NodeNum);

                    int _Length = 0;

                    head = nodeLength( head, &_Length );

                    if(NodeNum >= 1 && NodeNum <= --_Length)
                    head = deleteNode( head, NodeNum );

                    else
                    printf("given node is inaccessible\n");

                    break;


        case '3' : printf("value to delete : ");

                   int valueToDelete;
                   scanf("%d", &valueToDelete);

                   head = deleteNodeByDataValue( head, valueToDelete );

                   break;


        case '4' : head = deleteTail( head );

                   break;



        case '5' : head = transversalOfList( head );

                   break;


        case '6' : toQuit = true;

                   break;


    }



    if(!toQuit){
        printf("do you want to continue? (y/n) : ");

        fflushStdin();
        choice = getchar();
    }

}

return head;
}