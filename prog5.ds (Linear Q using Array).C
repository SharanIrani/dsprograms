#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define N 10
int QUEUE[N], FRONT=0, REAR=-1, ITEM;

void Qinsert() {
    if(REAR == N-1)
        printf("\n Queue Overflow");
    else {
        printf("\n Enter an item: ");
        scanf("%d", &ITEM);
        REAR++;
        QUEUE[REAR] = ITEM;
    }
}

void Qdelete() {
    if(REAR == FRONT - 1)
        printf("\n Queue Underflow");
    else if(REAR == FRONT) {
        printf("\n This is the last element in the queue");
        printf("\n The last element deleted is: %d", QUEUE[FRONT]);
        FRONT = 0;
        REAR = -1;
    } else {
        printf("\n Deleted item is %d", QUEUE[FRONT]);
        FRONT++;
    }
}

void Qdisplay() {
    int i;
    if(REAR == FRONT - 1)
        printf("\n No elements in Queue");
    else {
        printf("\n Queue: ");
        for(i = FRONT; i <= REAR; i++)
            printf("%d ", QUEUE[i]);  // Add space between elements
        printf("\n FRONT Element of the queue is: %d", QUEUE[FRONT]);
        printf("\n Rear Element of the queue is: %d", QUEUE[REAR]);
    }
}

int main() {
    int ch;
    for (;;) {
        printf("\n Queue Implementation using Array");
        printf("\n ***********");
        printf("\n 1.Insert into Queue");
        printf("\n 2.Delete from Queue");
        printf("\n 3.Display Queue");
        printf("\n 4.Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: Qinsert();
                    Qdisplay();
                    break;
            case 2: Qdelete();
                    Qdisplay();
                    break;
            case 3: Qdisplay();
                    break;
            case 4: 
                    getch(); // Pause before exit
                    clrscr(); // Clear the screen
                    return 0;
        }

        // Pause the program and clear the screen
        getch();
        clrscr();
    }

   
}

