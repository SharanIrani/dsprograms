#include<stdio.h>
#include<stdlib.h> // Include the necessary header for the exit function

#define MAXSTK 5

int TOP = -1;
int S[MAXSTK];

void push(); // Declare function prototypes
void pop();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("\n 1.Push");
        printf("\n 2.Pop");
        printf("\n 3.Display");
        printf("\n 4.Quit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0); // Exit with code 0
        default:
            printf("Wrong choice\n");
        }
    }

    return 0; // Indicate successful program execution
}

void push()
{
    int item;
    if (TOP == (MAXSTK - 1))
        printf("\nStack Overflow");
    else
    {
        printf("\n Enter the item to be pushed in stack: ");
        scanf("%d", &item);
        TOP = TOP + 1;
        S[TOP] = item;
    }
}

void pop()
{
    if (TOP == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped element is : %d\n", S[TOP]);
    TOP = TOP - 1;
}

void display()
{
    int i;
    if (TOP == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements: \n");
        for (i = TOP; i >= 0; i--)
            printf("%d\n", S[i]);
    }
}

