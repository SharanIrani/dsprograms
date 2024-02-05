#include <stdio.h>

void bubble_sort(int a[], int n) {
    int pass, temp, j;
    for (pass = 1; pass < n; pass++) {
        for (j = 0; j < n - pass; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, j, a[20], n, temp;

    clrscr();  // Clear the screen (Turbo C++ specific)

    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bubble_sort(a, n);

    printf("\nThe sorted elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    getch();  // Wait for a key press before closing the console window (Turbo C++ specific)

    return 0;
}

