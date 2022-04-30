#include <stdio.h>
#include <stdlib.h>

// you don't need to write vacancy twice
//
// typdef enum { empty = -1, full } vacancy;
// works fine
//
// looks like a varient of bool
// read below comments to know what I mean on line 84
typedef enum vacancy{
    empty = -1, full
} vacancy;

// Never name your function like that
// Choose whatever else format
// But not a shouting one
//
// Also, what's it returning if top == 2
vacancy ISEMPTY(int top){
    if(top == -1)
        return empty;
}

vacancy ISFULL(int top, int size){
    if(top == size-1)
        return full;
}

// although the function signature tells that
// you would be returning an int
// but you're returning nothing
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

    // again as the first comment
    //
    // also, you can give default values to them
    // int top = -1;
    // int bottom = 0;
    //
    // also, isn't bottom a const. It's always 0 and not changing
    //
    // Tip: make as many variable const as you can but not more
    // helps a compiler
    typedef struct stack{
        int top;
        int bottom;
        int size;
        int stack_array[3];
    } stack;

    stack input_array;

    input_array.top = -1;
    // if you have already made an array of 3 int
    // why count the size again
    // you could have made the size const
    // likt:
    // const int size = 3
    // int stack_array[size];
    input_array.size = sizeof(input_array.stack_array) / sizeof(input_array.stack_array[0]);
    input_array.bottom = 0;

    char answer = 'y';
    int frequency_of_running = 0;
    
    // same as first comment
    //
    // also, you could have just used bool instead of re-creating it
    // it seem like a form of bool
    //
    // you can just include <stdbool.h> and use the true and false
    // then it could be like
    //
    // bool escape = false;
    typedef enum escaping{
    escape, stay
    } escaping;

    escaping command = stay;

    // Give proper indentation
    // It matters
    while(answer == 'y' && command == stay) {
        frequency_of_running+=1; // ++frequency_of_running; but your wish here

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
                    --input_array.top;
                }
                break;

            case '2' :
                if(ISFULL(input_array.top, input_array.size) == full)
                    printf("STACK OVERFLOW\n");
                else {
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

            answer = getchar();
        }
    }

    if(ISEMPTY(input_array.top) != empty)
        for(int i = input_array.bottom; i <= input_array.top; i++)
                printf("element%d : %d\n", i+1, input_array.stack_array[i]);

    else
        printf("no element inside the stack that can be printed\n");

    printf("\n -------- stacking quitted -------- \n");

    return 0;
}
