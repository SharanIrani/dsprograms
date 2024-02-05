#include <stdio.h>

void toh(int, char, char, char);

int count = 0;

void toh(int n, char source, char temp, char dest)
{
    if (n > 0)
    {
        toh(n - 1, source, dest, temp);
        printf("\nMove disk: %d -> %c -> %c", n, source, dest);  // Added spaces for better formatting
        count++;
        toh(n - 1, temp, source, dest);
    }
}

int main(void)  // Changed void main() to int main(void)
{
    int n;
    char source = 'S', temp = 'T', dest = 'D';
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\nSequence is: ");
    toh(n, source, temp, dest);
    printf("\nThe number of moves is: %d\n", count);  // Corrected "moves are" to "moves is"
    return 0;  // Added a return statement
}
