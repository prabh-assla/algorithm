#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// use bool instead here also
// you're not even using getting_filled, why use enum
// It's just a true/false condition then
typedef enum{
    empty = -1, full, getting_filled
} vacancy;

// isEmpty 
// IsEmpty
// is_empty
// isempty
//
// use any of that
// but not this
vacancy isEMPTY(int front, int rear){
    if(front == rear+1)  // if you use bool instead of vacancy
        return empty;    // return true;
    else
        return getting_filled; // return false;
}

// Also, you can use bool also instead of vacancy
vacancy isFULL(int rear, int size){
    if(rear == size-1)
        return full;    // return true;
    else
        return getting_filled;    // return false;
}

// then it would be as easy as
// bool isFull(int rear, int size) {
//     return (rear == (size-1));
// }

bool PEAK(int front, int rear, int position){
    int index = --position;

    if((index <= rear-front) && (index >= 0))
        return true;

    else
        return false;
    // could be
    // return ((index <= rear-front) && (index >= 0))
}

// Perfect
void fflush_stdin(){
    char ch;
    do {
        ch = getchar();
    } while (ch != '\n' && ch != EOF);
}

int main(){
    typedef struct{
        int size;
        int front;
        int rear;
        int _queue_array[5];
    }  QUEUE;
    // Don't shout

    QUEUE q;

    q.size = 5;
    q.front = 0;
    q.rear = -1;

    char choice = 'y';

    bool want_to_quit = false, first_loop = true;

while((choice == 'y' || choice == 'Y') && want_to_quit == false){

    system("clear");

    printf("1.) enqueue\n2.) dequeue\n3.) front - |value, position| & rear - |value, position|\n4.) peak\n5.) isEMPTY?\n6.) isFULL?\n7.) empty\n8.) quit\n");

    if(first_loop == false)   // if (!first_loop)
    fflush_stdin();

    char option = getchar();

    switch(option) {
        case '1' : if(isFULL(q.rear, q.size) == full)
                    printf("queue overflow\n");

                    else{
                        int num;
                        printf("number to be inserted : ");
                        scanf("%d", &num);

                        q.rear++;
                        q._queue_array[q.rear] = num;
                    }

                    break;

        case '2' : if(isEMPTY(q.front, q.rear) == empty)
                    printf("queue underflow\n");

                    else{
                        int num = q._queue_array[q.front];

                        q.front++;

                        printf("the deleted number : %d\n", num);
                    }

                    break;

        case '3' : if(isEMPTY(q.front, q.rear) == empty)
                    printf("queue underflow\n");

                    else
                    printf("front - |%d, %d| & rear - |%d, %d|\n", q._queue_array[q.front], q.front, q._queue_array[q.rear], q.rear);

                    break;

        case '4' : if(isEMPTY(q.front, q.rear) == empty)
                    printf("queue underflow\n");

                    else{
                        int position;
                        bool index_accessible;

                        printf("position of number : ");
                        scanf("%d", &position);

                        int index = position-1;

                    index_accessible = PEAK(q.front, q.rear, position);

                        if(index_accessible == false)
                            printf("the number is inaccessible\n");

                        else
                            printf("the number at %dth position is %d\n", index+1, q._queue_array[q.front+index]);
                    }

                    break;

        case '5' : if(isEMPTY(q.front, q.rear) == empty)
                    printf("queue underflow\n");

                    else
                    printf("not empty\n");

                    break;

        case '6' : if(isFULL(q.rear, q.size) == full)
                    printf("queue overflow\n");

                    else
                    printf("not full\n");

                    break;

        case '7' : if(isEMPTY(q.front, q.rear) == empty)
                    printf("queue underflow\n");

                    else
                        q.front = q.rear+1;

                    break;

        case '8' : want_to_quit = true;

                    break;
    }

            if(want_to_quit == false){
                printf("do you wish to continue(y/n) : ");

                fflush_stdin();
                
                int choice = getchar();
            }

first_loop = false;
}

        for(int i = q.front; i<=q.rear; i++)
            printf("queue[%d] = %d\n", i+1, q._queue_array[i]);

        printf("queueing now stops ----------------- \n\a");

return 0;
}
