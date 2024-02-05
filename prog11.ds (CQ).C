#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int info;
    struct queue *link;
};

struct queue *front = NULL, *rear = NULL;

void Qinsert(int item)
{
    struct queue *new_node;
    new_node = (struct queue*)malloc(sizeof(struct queue));
    new_node->info = item;
    new_node->link = NULL;
    
    if (front == NULL && rear == NULL)
    {
        front = rear = new_node;
        rear->link = front;
    }
    else
    {
        rear->link = new_node;
        rear = new_node;
        rear->link = front;
    }
}

void QDelete()
{
    struct queue *ptr;
    ptr = front;

    if (front == NULL && rear == NULL)
        printf("\n Queue is empty");
    else if (front == rear)
    {
        front = rear = NULL;
        printf("\n The value being deleted is : %d", ptr->info);
        free(ptr);
    }
    else
    {
        front = front->link;
        rear->link = front;
        printf("\n The value being deleted is : %d", ptr->info);
        free(ptr);
    }
}

void Display()
{
    struct queue *ptr;
    ptr = front;

    if (front == NULL && rear == NULL)
        printf("\n Queue is empty");
    else
    {
        printf("\n The Queue Elements are: ");
        do
        {
            printf("%d ", ptr->info);
            ptr = ptr->link;
        } while (ptr != front);
    }
}

int main()
{
    int val, choice;

    do
    {
        printf("\n 1.Insert");
        printf("\n 2.Delete");
        printf("\n 3.Display");
        printf("\n 4.Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Enter the number to insert into Queue :");
            scanf("%d", &val);
            Qinsert(val);
            break;
        case 2:
            QDelete();
            break;
        case 3:
            Display();
            break;
        }
    } while (choice != 4);

    return 0;
}
