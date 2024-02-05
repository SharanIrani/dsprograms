#include<stdio.h>
#include<stdlib.h>

struct node {
    int INFO;
    struct node *LINK;
};

typedef struct node NODE;
NODE *start = NULL;

void insertOrdered(int data) {
    NODE *NEWNODE = (NODE*)malloc(sizeof(NODE));
    NEWNODE->INFO = data;

    if (start == NULL) {
        start = NEWNODE;
        start->LINK = NULL;
    } else if (data < start->INFO) {
        NEWNODE->LINK = start;
        start = NEWNODE;
    } else {
        NODE *PREVPTR = start;
        NODE *CURRPTR = start->LINK;

        while (CURRPTR != NULL && data > CURRPTR->INFO) {
            PREVPTR = CURRPTR;
            CURRPTR = CURRPTR->LINK;
        }

        PREVPTR->LINK = NEWNODE;
        NEWNODE->LINK = CURRPTR;
    }
}

void deleteOrdered(int data) {
    NODE *PREVPTR = start;
    NODE *CURRPTR = start->LINK;

    if (start == NULL) {
        printf("\n List is Empty");
    } else if (data == start->INFO) {
        start = CURRPTR;
        free(PREVPTR);
    } else {
        while (CURRPTR != NULL && CURRPTR->INFO != data) {
            PREVPTR = CURRPTR;
            CURRPTR = CURRPTR->LINK;
        }

        if (CURRPTR != NULL) {
            PREVPTR->LINK = CURRPTR->LINK;
            free(CURRPTR);
        } else {
            printf("\n Data not found in the List ");
        }
    }
}

void display() {
    NODE *CURRPTR = start;

    if (CURRPTR == NULL) {
        printf("\n Empty");
    } else {
        while (CURRPTR != NULL) {
            printf("%d", CURRPTR->INFO);
            printf("->");
            CURRPTR = CURRPTR->LINK;
        }
        printf("NULL\n");
    }
}

int main() {
    int ch, data;

    while (1) {
        printf("\n Ordered Linked List Operations");
        printf("\n*************");
        printf("\n 1.Insert");
        printf("\n 2.Delete");
        printf("\n 3.Display");
        printf("\n 4.Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n Enter Data to be Inserted: ");
                scanf("%d", &data);
                printf("\n Linked list before insertion is : \n");
                display();
                insertOrdered(data);
                printf("\n Linked list after insertion is : \n");
                display();
                break;
            case 2:
                printf("\n Enter data to be deleted : ");
                scanf("%d", &data);
                printf("\n Linked list before Deletion is : \n");
                display();
                deleteOrdered(data);
                printf("\n Linked list after Deletion is : \n");
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                // Exit the loop using break instead of exit(0);
                break;
        }
    }

    return 0;
}

