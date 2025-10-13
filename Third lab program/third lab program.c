#include<stdio.h>
#include<stdlib.h>
#define N 3

int queue[N];
int front=-1, rear=-1;

void enque()
{
    int item;
    if(rear==N-1){
        printf("Overflow!, cannot insert the element\n");
        return;
    }
    printf("enter the item to insert:\n");
    scanf("%d",&item);
    if(front==-1)
        front=0;
    rear ++;
    queue [rear]=item;
    printf("inserted %d into the queue",item);
}
void deque()
{
    if(front==-1 || front>rear){
        printf("Underflow!,empty queue cannot delete\n");
        return;
    }
    printf("Deleted %d from the queue",queue[front]);
    front ++;
    if(front > rear)
        front=rear=-1;
}
void display()
{
    if(front==-1)
    {
        printf("Empty queue! nothing to display");
    }
    printf("\nThe queue elements are:");
    for(int i=front; i<=rear; i++)
        printf("%d",queue[i]);
}

int main()
{
    int choice;
    while(1){
    printf("--- queue operations ---");
    printf("\n 1. Insert");
    printf("\n 2. Delete");
    printf("\n 3. Display");
    printf("\n 4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
    case 1:
        enque();
        break;
    case 2:
        deque();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
    default: printf("Invalid input! try again");
        }
        printf("\n");
    }
}
