#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

int top = -1;
char stack_arr[MAX];

/* Function prototypes */
void push(char item);
char pop(void);
int match(char a, char b);
int check(const char exp[]);

int main(void)
{
    char exp[MAX];

    printf("Enter an expression: ");
    if (fgets(exp, sizeof(exp), stdin) == NULL) {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    /* Remove trailing newline if present */
    size_t len = strlen(exp);
    if (len > 0 && exp[len - 1] == '\n') {
        exp[len - 1] = '\0';
    }

    if (check(exp)) {
        printf("Balanced Parentheses\n");
    } else {
        /* Messages for imbalance are printed inside check() */
    }
    return 0;
}

int check(const char exp[])
{
    top = -1; /* reset stack for each check */
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                printf("Right parentheses are more than left parentheses at index %d\n", i);
                return 0;
            } else {
                char temp = pop();
                if (!match(temp, exp[i])) {
                    printf("Mismatched parentheses are: %c and %c at index %d\n", temp, exp[i], i);
                    return 0;
                }
            }
        }
        /* Ignore non-parenthesis characters */
    }

    if (top == -1) {
        return 1;
    } else {
        printf("Left parentheses more than right parentheses\n");
        return 0;
    }
}

int match(char a, char b)
{
    if (a == '[' && b == ']') return 1;
    if (a == '{' && b == '}') return 1;
    if (a == '(' && b == ')') return 1;
    return 0;
}

void push(char item)
{
    if (top == (MAX - 1)) {
        printf("Stack Overflow\n");
        /* For safety, do not push beyond capacity */
        return;
    }
    stack_arr[++top] = item;
}

char pop(void)
{
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[top--];
}
