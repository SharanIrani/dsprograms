#include<stdio.h>
#include<stdlib.h>

int Lsearch(int A[], int n, int key) {
    int i = -1;
    while (i < n - 1) {
        if (A[++i] == key)
            return i;
    }
    return -1;
}

int Bsearch(int A[], int n, int key) {
    int first = 0;
    int last = n - 1;
    int mid;
    while (first <= last) {
        mid = (first + last) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            last = mid - 1;
        else
            first = mid + 1;
    }
    return -1;
}

void acceptInput(int A[], int *n, int *key) {
    int i;
    printf("Enter the number of elements: ");
    scanf("%d", n);
    for (i = 0; i < *n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &A[i]);
    }
    printf("Enter an element to be searched: ");
    scanf("%d", key);
}

int main() {
    int ch, flag, n, key;
    int A[100];  // Assuming a maximum array size of 100

    while (1) {
        printf("\nSearching Techniques");
        printf("\n*********");
        printf("\n1. Linear Search");
        printf("\n2. Binary Search");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                acceptInput(A, &n, &key);
                flag = Lsearch(A, n, key);
                if (flag == -1)
                    printf("\nSearch is Unsuccessful");
                else
                    printf("\nElement %d found at position: %d", key, flag + 1);
                break;

            case 2:
                printf("\nEnter elements in Ascending order for Binary Search\n");
                acceptInput(A, &n, &key);
                flag = Bsearch(A, n, key);
                if (flag == -1)
                    printf("%d not found in array\n", key);
                else
                    printf("Element %d found at position: %d", key, flag + 1);
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice. Please enter a valid option.");
        }
    }

    return 0;
}
