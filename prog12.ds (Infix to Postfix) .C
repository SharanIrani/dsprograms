#include <stdio.h> //[2+3 ->23+]
#include <string.h>

#define MAX 20

char s[MAX];
int top = 0;

int isnum(char ch) {
    return (ch >= '0' && ch <= '9');
}

int precedence(char elem);

void push(char elem);

int pop();

int main() {
    char infix[MAX], postfix[MAX], ch, elem;
    int i = 0, j = 0;

    printf("\n\t\t Program to Convert infix to postfix Expression ");
    printf("\n Enter the Infix Expression  :\n");
    scanf("%s", infix);

    push('#');

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];
        if (isnum(ch))
            postfix[j++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')') {
            while (s[top] != '(')
                postfix[j++] = pop();
            elem = pop(); // Pop the opening parenthesis '('
        } else {
            while (precedence(s[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (s[top] != '#')
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("\n Postfix expression conversion is : \n %s\n", postfix);

    return 0;
}

int precedence(char elem) {
    switch (elem) {
        case '+':
        case '-':
            return 1;
        case '/':
            return 2;
        case '^':
            return 3;
        case '#':
            return 0;
        default:
            return -1; // Added a default case for unknown operators or characters
    }
}

void push(char elem) {
    ++top;
    s[top] = elem;
}

int pop() {
    char elem;
    elem = s[top];
    --top;
    return (elem);
}
