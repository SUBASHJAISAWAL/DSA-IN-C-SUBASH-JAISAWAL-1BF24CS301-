#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void push(int);
void pop();
void peek();
void display();

int stack[SIZE], top = -1;

int main(){
    int value, choice;
    while(1){
        printf("*** MENU***");
        printf("\n 1. push\n 2. pop\n 3. peek\n 4. Display\n 5. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to push: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong selection!!! Try again!!!\n");
        }
    }
    return 0;
}

void push(int value){
    if (top == SIZE - 1){
        printf("\nThe stack is full!!! Insertion is not possible\nStack overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("Insertion success\n");
    }
}

void pop(){
    if (top == -1){
        printf("\nStack is empty, deletion not possible\nStack underflow\n");
    } else {
        printf("\nDeleted: %d\n", stack[top]);
        top--;
    }
}

void peek(){
    if(top == -1){
        printf("Stack underflow\n");
    } else {
        printf("%d\n", stack[top]);
    }
}

void display(){
    if (top == -1){
        printf("\nStack is empty\n");
    } else {
        int i;
        printf("\nStack elements are:\n");
        for(i = top; i >= 0; i--){
            printf("%d ", stack[i]);
        }

    }
}
