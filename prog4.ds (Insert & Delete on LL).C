#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int INFO;
    struct node *LINK;
};

typedef struct node NODE;

NODE *start = NULL;

void create()
{
    char ch;
    int i = 0;
    NODE *CURRPTR, *NEWNODE;
    CURRPTR = (NODE*)malloc(sizeof(NODE));
    start = CURRPTR;

    while (1)
    {
        printf("\nEnter the node %d: ", i + 1);
        scanf("%d", &CURRPTR->INFO);
        printf("\nDo you wish to add one more node (Y/N): ");
        ch = getche();

        if (toupper(ch) == 'Y')
        {
            NEWNODE = (NODE*)malloc(sizeof(NODE));
            CURRPTR->LINK = NEWNODE;
            CURRPTR = NEWNODE;
        }
        else
        {
            CURRPTR->LINK = NULL;
            break;
        }
        i++;
    }
}

void display()
{
    NODE *CURRPTR = start;

    if (start == NULL)
        printf("\nThe Linked list is empty");
    else
    {
        while (CURRPTR != NULL)
        {
            printf("%d -> ", CURRPTR->INFO);
            CURRPTR = CURRPTR->LINK;
        }
        printf("NULL");
    }
}

int length()
{
    int len = 0;
    NODE *CURRPTR;

    if (start == NULL)
    {
        printf("The Linked list is empty");
        return (len);
    }

    CURRPTR = start;
    while (CURRPTR != NULL)
    {
        len++;
        CURRPTR = CURRPTR->LINK;
    }

    return (len);
}

void insert_beg(int item)
{
    NODE *NEWNODE;
    NEWNODE = (NODE*)malloc(sizeof(NODE));
    NEWNODE->INFO = item;
    NEWNODE->LINK = start;
    start = NEWNODE;
}

void insert_end(int item)
{
    NODE *CURRPTR, *NEWNODE;
    if (start == NULL)
    {
        NEWNODE = (NODE*)malloc(sizeof(NODE));
        NEWNODE->INFO = item;
        NEWNODE->LINK = NULL;
        start = NEWNODE;
    }
    else
        CURRPTR = start;

    while (CURRPTR->LINK != NULL)
    {
        CURRPTR = CURRPTR->LINK;
    }

    NEWNODE = (NODE*)malloc(sizeof(NODE));
    NEWNODE->INFO = item;
    CURRPTR->LINK = NEWNODE;
    NEWNODE->LINK = NULL;
}

void insert_pos(int item, int pos)
{
    int i;
    NODE *CURRPTR = start, *NEWNODE;

    if (pos == 1)
        insert_beg(item);
    else
    {
        for (i = 0; i < pos - 2; i++)
        {
            CURRPTR = CURRPTR->LINK;
        }

        NEWNODE = (NODE*)malloc(sizeof(NODE));
        NEWNODE->INFO = item;
        NEWNODE->LINK = NEWNODE;
    }
}

void delete_beg()
{
    NODE *CURRPTR;

    if (start == NULL)
    {
        printf("\nThe linked list is empty\n");
        return;
    }
    else
    {
        CURRPTR = start;
        start = start->LINK;
        free(CURRPTR);
    }
}

void delete_end()
{
    NODE *CURRPTR, *PREVPTR;

    if (start == NULL)
        printf("\nThe Linked list is empty");
    else if (start->LINK == NULL)
    {
        start = NULL;
        return;
    }
    else
    {
        CURRPTR = start;
        PREVPTR = NULL;

        while (CURRPTR->LINK != NULL)
        {
            PREVPTR = CURRPTR;
            CURRPTR = CURRPTR->LINK;
        }

        PREVPTR->LINK = NULL;
    }
}

void delete_pos(int POS)
{
    int i;
    NODE *CURRPTR = start, *PREVPTR;

    if (POS == 1)
        delete_beg();
    else
    {
        CURRPTR = start;
        PREVPTR = NULL;

        for (i = 1; i < POS; i++)
        {
            PREVPTR = CURRPTR;
            CURRPTR = CURRPTR->LINK;
        }

        PREVPTR->LINK = CURRPTR->LINK;
    }
}

void delete_item(int item)
{
    NODE *CURRPTR = start, *PREVPTR = NULL;

    if (start == NULL)
    {
        printf("\nThe linked list is empty");
        return;
    }
    else if (start->INFO == item)
    {
        start = start->LINK;
        free(CURRPTR);
        return;
    }
    else
    {
        while (CURRPTR != NULL && CURRPTR->INFO != item)
        {
            PREVPTR = CURRPTR;
            CURRPTR = CURRPTR->LINK;
        }

        if (CURRPTR == NULL)
            printf("\nThe item is not found in the linked list\n");
        else
            PREVPTR->LINK = CURRPTR->LINK;
    }
}

void main()
{
    int ch, item, pos;

    while (1)
    {

        printf("\n1. Create a Linked List");
        printf("\n2. Display");
        printf("\n3. Insert First Node");
        printf("\n4. Insert at the End");
        printf("\n5. Insert at specified position");
        printf("\n6. Delete First Node");
        printf("\n7. Delete Last Node");
        printf("\n8. Delete at Specified Position");
        printf("\n9. Delete a Node when item is given");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            start = NULL;
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\nEnter the item to insert at the beginning: ");
            scanf("%d", &item);
            printf("\nLinked list before insertion is:\n");
            display();
            insert_beg(item);
            printf("\nLinked List after insertion is:\n");
            display();
            break;
        case 4:
            printf("\nEnter the item to insert at the End: ");
            scanf("%d", &item);
            printf("\nLinked list before insertion is:\n");
            display();
            insert_end(item);
            printf("\nLinked list after insertion is:\n");
            display();
            break;
        case 5:
            printf("\nEnter an item to insert at a certain position: ");
            scanf("%d", &item);
            printf("\nEnter a valid position: ");
            scanf("%d", &pos);

            if ((pos == 0) || (pos > length() + 1))
            {
                printf("\nInvalid position\n");
                break;
            }
            else
            {
                printf("\nLinked list before insertion is:\n");
                display();
                insert_pos(item, pos);
                printf("\nLinked list after insertion is:\n");
                display();
                break;
            }
        case 6:
            printf("\nLinked list before deletion is:\n");
            display();
            delete_beg();
            printf("\nLinked list after deletion is:\n");
            display();
            break;
        case 7:
            printf("\nLinked list before deletion is:\n");
            display();
            delete_end();
            printf("\nLinked list after deletion is:\n");
            display();
            break;
        case 8:
            printf("Enter a valid position to delete:\n");
            scanf("%d", &pos);
            if ((pos == 0) || (pos > length()))
            {
                printf("\nInvalid position\n");
                break;
            }
            else
            {
                printf("\nLinked list before deletion is:\n");
                display();
                delete_pos(pos);
                printf("\nLinked list after deletion is:\n");
                display();
                break;
            }
        case 9:
            printf("\nLinked list before deletion is:\n");
            display();
            printf("Enter an item to be deleted: ");
            scanf("%d", &item);
            delete_item(item);
            printf("\nLinked list after deletion is:\n");
            display();
            break;
        case 10:
            exit(0);
        }
        getch();  // Wait for a key press before continuing (Turbo C++ specific)
    }
}

