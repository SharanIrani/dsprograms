#include<stdio.h>
#include<stdlib.h>

#define N 10
int QUEUE[N], FRONT = -1, REAR = -1, ITEM;

void CQinsert() {
    if ((FRONT == (REAR + 1) % N))
        printf("\n Queue Overflow");
    else {
        printf("\n Enter the element to be Inserted : ");
        scanf("%d", &ITEM);
        if (FRONT == -1)
            FRONT = REAR = 0;
        else
            REAR = (REAR + 1) % N;
        QUEUE[REAR] = ITEM;
    }
}

void CQdisplay() {
    int i;
    if (FRONT == -1)
        printf("\n No elements in the CQueue");
    else {
        printf("\n Circular Queue: ");
        if (FRONT <= REAR) {
            for (i = FRONT; i <= REAR; i++)
                printf("%d ", QUEUE[i]);
        } else {
            for (i = FRONT; i <= N - 1; i++)
                printf("%d ", QUEUE[i]);
            for (i = 0; i <= REAR; i++)
                printf("%d ", QUEUE[i]);
        }
        printf("\n Front elements of the Queue is : %d", QUEUE[FRONT]);
        printf("\n Rear Element of the Queue is : %d", QUEUE[REAR]);
    }
}

void CQdelete() {
    if (FRONT == -1)
        printf("\n Queue Underflow");
    else {
        ITEM = QUEUE[FRONT];
        printf("\n The Deleted item is : %d", QUEUE[FRONT]);
        if (FRONT == REAR)
            FRONT = REAR = -1;
        else
            FRONT = (FRONT + 1) % N;
    }
}

void main() {
    int ch;
    while (1) {
        printf("\n Circular Queue Implementation using Array");
        printf("\n **********");
        printf("\n 1. Circular Queue Insert");
        printf("\n 2. Circular Queue Delete");
        printf("\n 3. Circular Queue Display");
        printf("\n 4. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                CQinsert();
                CQdisplay();
                break;
            case 2:
                CQdelete();
                CQdisplay();
                break;
            case 3:
                CQdisplay();
                break;
            case 4:
                exit(0);
        }
    }
}


