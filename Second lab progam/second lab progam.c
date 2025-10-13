#include <stdio.h>
#include <ctype.h>
#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char element) {
    stack[++top] = element;
}

char pop() {
    return stack[top--];
}

int pr(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char infix[50], postfix[50], ch, element;
    int i = 0, k = 0;
    printf("Enter the Infix expression: ");
    scanf("%49s", infix);

    push('#');
    while ((ch = infix[i++]) != '\0') {
        if (ch == '(') {
            push(ch);
        } else if (isalnum((unsigned char)ch)) {
            postfix[k++] = ch;
        } else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            element = pop();
            (void)element;
        } else {
            while (stack[top] != '(' && pr(stack[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (stack[top] != '#')
        postfix[k++] = pop();

    postfix[k] = '\0';
    printf("\nPostfix = %s\n", postfix);
    return 0;
}
