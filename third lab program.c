#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert more elements.\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &item);
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = item;
    printf("Inserted %d into the queue.\n", item);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! No elements to delete.\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1;  // Reset queue when empty
    }
}

void display() {
    if (front == -1) {
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("\nQueue elements are: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\n--- Queue Operations ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
