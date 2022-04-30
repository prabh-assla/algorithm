#include <stdio.h>
#include <stdlib.h>

//lifo

typedef enum vacancy{
    empty = -1, full
} vacancy;

vacancy ISEMPTY(int top){
    if(top == -1)
        return empty;
}

vacancy ISFULL(int top, int size){
    if(top == size-1)
        return full;
}

int peak(int input_array[], int top, int position){
int num_index = position-1;

    if(top - num_index < 0)
        printf("the number position is inaccessible\n");
    else
        printf("number at %d position is : %d\n", position, input_array[num_index]);

}

void fflush_stdin(){
    int c;
    do{
        c = getchar();
    } while(c != '\n' && c != EOF);
}

int main(){

    typedef struct stack{
        int top;
        int bottom;
        int size;
        int stack_array[3];
    } stack;

    stack input_array;

    input_array.top = -1;
    input_array.size = sizeof(input_array.stack_array) / sizeof(input_array.stack_array[0]);
    input_array.bottom = 0;

    char answer = 'y';
    int frequency_of_running = 0;
    
    typedef enum escaping{
    escape, stay
    } escaping;

    escaping command = stay;

while(answer == 'y' && command == stay){
    frequency_of_running+=1;

    system("clear");
    
    printf("1.) pop\n2.) push\n3.) peek\n4.) print stacktop position & element AND stackbottom position & element\n5.) empty\n6.) quit\n");
    
    if(frequency_of_running != 1)
    fflush_stdin();

    char choice = getchar();

    switch(choice){
        case '1' :
            if(ISEMPTY(input_array.top) == empty)
            printf("STACK UNDERFLOW\n");

            else{
            int num = input_array.stack_array[input_array.top];

            printf("number that was deleted : %d\n", num);

            --input_array.top;}
        break;

        case '2' :
            if(ISFULL(input_array.top, input_array.size) == full)
            printf("STACK OVERFLOW\n");

            else{
            ++input_array.top;

            int num;
            printf("number to be inserted : ");

            scanf("%d", &num);
    

            input_array.stack_array[input_array.top] = num;
            }
        break;

        case '3' :
            printf("which number position you wish to access : ");     
            int num;
            scanf("%d", &num);
    

            peak(input_array.stack_array, input_array.top, num);
        break;

        case '4' :
            if(ISEMPTY(input_array.top) == empty)
            printf("STACK UNDERFLOW\n");

            else
            printf("STACKBOTTOM[%d] = %d & STACKTOP[%d] = %d\n", input_array.bottom,
            input_array.stack_array[input_array.bottom], input_array.top,
            input_array.stack_array[input_array.top]);
        break;

        case '5' :
            if(ISEMPTY(input_array.top) == empty)
            printf("STACK UNDERFLOW\n");

            else
            input_array.top = -1;
        break;

        case '6' :
            command = escape;
}

if(command != escape){
    printf("your choice (y/n) : ");
    fflush_stdin();

    answer = getchar();}
}

    if(ISEMPTY(input_array.top) != empty)
        for(int i = input_array.bottom; i <= input_array.top; i++)
                printf("element%d : %d\n", i+1, input_array.stack_array[i]);

    else
        printf("no element inside the stack that can be printed\n");

    printf("\n -------- stacking quitted -------- \n");

return 0;
}