void insertionSORT(float input[], int size){
    for(int i=1; i<size; i++){
    
    float static_num = input[i];
    int j;

        for(j=i-1; j>=0; j--){
        float dynamic_num = input[j];

        if(static_num < dynamic_num)
        input[j+1] = dynamic_num;

        else
        break;}
    
    input[j+1] = static_num;

    j=0;
    }

}