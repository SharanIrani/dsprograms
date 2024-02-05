#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int a[100], n;

int findMaxIndex(int a[], int k, int n) {
    int loc, j, max;
    max = a[k];
    loc = k;
    for (j = k + 1; j < n; j++)
        if (max < a[j]) {
            max = a[j];
            loc = j;
        }
    return loc;
}

void insert_sort(int a[], int n) {
    int pass, k, temp, j;
    for (pass = 1; pass < n; pass++) {
        k = a[pass];
        for (j = pass - 1; j >= 0 && k > a[j]; j--)
            a[j + 1] = a[j];
        a[j + 1] = k;
    }
}

void acceptInput() {
    int i;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display() {
    int i;
    printf("\nThe Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void main() {
    int k, temp, loc, ch;
    while (1) {
        printf("\nSorting Techniques");
        printf("\n********");
        printf("\n1. Insertion Sort");
        printf("\n2. Selection Sort");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
                acceptInput();
                insert_sort(a, n);
                display();
                break;
            case 2: 
                acceptInput();
                for (k = 0; k < n; k++) {
                    loc = findMaxIndex(a, k, n);
                    temp = a[k];
                    a[k] = a[loc];
                    a[loc] = temp;
                }
                display();
                break;
            case 3: 
                exit(0);
        }
        getch();
        clrscr();
    }
}

