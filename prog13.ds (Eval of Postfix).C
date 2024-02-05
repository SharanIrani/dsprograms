#include<stdio.h>
#include<string.h>
#include<math.h>
//23+->5
#define MAX 20
int S[MAX], top = 0;

void push(int element) {
    ++top;
    S[top] = element;
}

int pop() {
    int element = S[top];
    --top;
    return element;
}

void main() {
    char postfix[MAX], ch;
    int i, op1, op2, res;
    
    printf("\n\t\t Program to Evaluate Postfix Expression");
    printf("\n\t\t Enter the postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; i < strlen(postfix); i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
                case '^': res = pow(op1, op2); break;
                default: printf("Invalid Character\n");
            }
            push(res);
        }
    }

    printf("Result of the above expression is : %d\n", pop());
}

