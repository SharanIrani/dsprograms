#include <stdio.h>
#include <stdlib.h>
//1,7,18,15,40,50,30,17,41,3
struct node {
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;

NODE *root = NULL;

NODE *getInsuccessor(NODE *ptr);

void disp(struct node *ptr, int level) {
    int i;
    if (ptr != NULL) {
        disp(ptr->right, level + 1);
        for (i = 0; i < level; i++)
            printf(" ");
        printf("%d\n", ptr->info);
        disp(ptr->left, level + 1);
    }
}

void create(int item) {
    NODE *newnode, *currptr, *ptr;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = item;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
        root = newnode;
    else {
        currptr = root;
        while (currptr != NULL) {
            ptr = currptr;
            if (item > currptr->info)
                currptr = currptr->right;
            else
                currptr = currptr->left;
        }
        if (item < ptr->info)
            ptr->left = newnode;
        else
            ptr->right = newnode;
    }
}

NODE *deletion(NODE *p, int item) {
    NODE *temp;
    if (p == NULL) {
        printf("Unable to delete, No such key exists\n");
        return p;
    } else if (item > p->info)
        p->right = deletion(p->right, item);
    else if (item < p->info)
        p->left = deletion(p->left, item);
    else {
        if (p->left == NULL) {
            temp = p->right;
            free(p);
            return temp;
        } else if (p->right == NULL) {
            temp = p->left;
            free(p);
            return temp;
        }
        temp = getInsuccessor(p->right);
        p->info = temp->info;
        p->right = deletion(p->right, temp->info);
    }
    return p;
}

NODE *getInsuccessor(NODE *ptr) {
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

int main() {
    int item, ch, i, n;
    while (1) {
        printf("\n Binary Search Tree MENU ");
        printf("\n 1.Insert");
        printf("\n 2.Delete");
        printf("\n 3.Display");
        printf("\n 4.Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("\n Enter the number of Nodes: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                printf("\n Enter the data for the node: ");
                scanf("%d", &item);
                create(item);
            }
            break;
        case 2:
            printf("\n Enter an Item to be Deleted: ");
            scanf("%d", &item);
            root = deletion(root, item);
            break;
        case 3:
            printf("\n The Binary Tree Nodes are: \n\n");
            disp(root, 1);
            break;
        case 4:
            exit(1);
        }
    }
   
}
