#include<stdio.h>
#include<stdlib.h>
#define SIZE 2
void push(int);
void pop();
void peek();
void display();
int stack[SIZE], top=-1;
void main(){
    int value,choice;
    while(1){
            printf("***MENU***");
            printf("\n 1. push\n 2. pop\n 3. peek\n 4.Display\n 5. Exit\n");
            printf("Enter you choice:");
            scanf("%d",&choice);
            switch(choice){
                case 1: printf("Enter the value to be inserted: ");
                        scanf("%d",&value);
                        push(value);
                        break;
                case 2: pop();
                        break;
                case 3: peek();
                        break;
                case 4:display();
                        break;
                case 5:exit(0);
                        break;
                default:printf("\nWrong selection!!! Try again!!!");
                    }
    }
    }
void push(int value){
    if (top==SIZE-1){
        printf("\nStack is full!!! Insertion is not possible\nStack overflow");
    }
    else{
        top++;
        stack[top]=value;
        printf("\nInsertion success!");
    }
}
void pop(){
    if (top==-1)
        printf("\nStack is empty, deletion not possible !\n Stack underflow");
    else{
        printf("\nDeleted: %d",stack[top]);
        top--;
    }
}
void peek(){
    if(top==-1){
        printf("Stack underflow");
    }
    else{
        printf("%d",stack[top]);
    }
}
void display(){
if(top==-1){
    printf("\n Stack is empty");
}
else{
    int i;
    printf("\nStack elements are:");
        for (i=top; i>=0;i--)
            printf("\n%d\n",stack[i]);
}
}
