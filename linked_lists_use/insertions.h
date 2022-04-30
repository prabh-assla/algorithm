

node* insertionAtFront( node* head, int num ){
    node* beforeHead = (node*) malloc( nodeSize );

    beforeHead -> data = num;

    beforeHead -> linker = head;

    return beforeHead;

}


node* replaceNode(node* head, int nodePosition, int num){

    node* RunTillaptNode = (node*) malloc( nodeSize );

    RunTillaptNode = head;

    int index = 0;

    while( index != nodePosition ){

    RunTillaptNode = RunTillaptNode -> linker;

    ++index;
    }

    RunTillaptNode -> data = num;

return head;
}


node* insertNewNOde( node* head, int nodeNumber, int num ){


    node* RunTillaptNode = ( node* ) malloc( nodeSize );
    node* OneStepLess = ( node* ) malloc( nodeSize );

    RunTillaptNode = head -> linker;
    OneStepLess = head;

    int index = 0;

    while( index != nodeNumber ){

        RunTillaptNode = RunTillaptNode -> linker;
        OneStepLess = OneStepLess -> linker;

        ++index;
    }

            node* newNode = ( node* ) malloc( nodeSize );

            OneStepLess -> linker = newNode;
            newNode -> data = num;
            newNode -> linker = RunTillaptNode;


return head;
}


node* insertionAtback( node* head, int num ){

    node* toRunTillTail = (node*) malloc( nodeSize );

    toRunTillTail = head;

    while( toRunTillTail -> linker != NULL)
        toRunTillTail = toRunTillTail -> linker;

    node* afterTail = (node*) malloc( nodeSize );

    toRunTillTail -> linker = afterTail;
    afterTail -> data = num;
    afterTail -> linker = NULL;


return head;
}



node* INSERTION( node* head ){

    char choice = 'y';

    bool toQuit = false;

while((choice == 'y' || choice == 'Y') && !toQuit ){

    system("clear");

    printf("1.) insert at front\n2.) replace node||head||tail\n3.) insert after node\n4.) insert at back\n5.) transversal of list\n6.) quit\n");

    fflushStdin();

    char option = getchar();

    switch( option ){
        case '1' : printf("data to insert at front : ");

                   int num;
                   scanf("%d", &num);

                   head = insertionAtFront( head, num );

                   break;



        case '2' :  printf("");
                    int _length = 0;

                    head = nodeLength( head, &_length );

                    printf("node to replace (0 - head & %d - tail) : ", _length);

                    int nodeNumber;
                    scanf("%d", &nodeNumber);

                    if(nodeNumber >= 0 && nodeNumber <= _length){


        if(nodeNumber == 0)
        printf("head data to replace with : ");

        if(nodeNumber == _length)
        printf("tail data to replace with : ");
        
        if(nodeNumber > 0 && nodeNumber < _length)
        printf("node%d data to replace with : ", nodeNumber);


                    int Num;
                    scanf("%d", &Num);

                    head = replaceNode( head, nodeNumber, Num );
                    }


                    else
                    printf("given node is inaccessible\n");

                    break;



        case '3' :  printf("node after which to insert : ");

                    int NodeNumber;
                    scanf("%d", &NodeNumber);

                    int Length = 0;

                    head = nodeLength( head, &Length );


                    if(NodeNumber >= 1 && NodeNumber <= --Length){
                    printf("data to insert at New Node : ");

                    int _num;
                    scanf("%d", &_num);

                    head = insertNewNOde( head, NodeNumber, _num );
                    }

                    else
                    printf("given node is inaccessible\n");

                    break;



        case '4' : printf("number to insert at back : ");

                   int _num_;
                   scanf("%d", &_num_);

                   head = insertionAtback( head, _num_ );

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