#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void createlist(int n)
{
    struct node *newnode, *temp = NULL;
    int data, i;

    if(n<=0)
    {
        printf("Number of nodes cannot be less or equal to 0.\n");
        return;
    }

    for(i=1;i<=n;i++)
    {
        newnode = (struct node *) malloc(sizeof(struct node));
        if(newnode == NULL)
        {
            printf("Memory Allocation failed.\n");
            return;
        }

        printf("Enter data for the node %d:", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp->next = newnode;
        }
        temp = newnode;
    }
    printf("Linked list created successfully!\n");
}

void deletefirst()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void deletelast()
{
    struct node *temp, *prev;
    if(head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if(head->next == NULL)
    {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;   // FIXED
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted element: %d\n", temp->data);
    prev->next = NULL;
    free(temp);
}

void deleteSpecific(int value)
{
    struct node *temp = head, *prev = NULL;

    if(head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if(head->data == value)
    {
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Element %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void displayList()
{
    struct node *temp = head;
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, n, value;

    while(1)
    {
        printf("\n---Singly linked list operations---\n");
        printf("1. Create list\n");
        printf("2. Delete first element\n");
        printf("3. Delete specific element\n");
        printf("4. Delete Last element\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of nodes:");
                scanf("%d", &n);
                createlist(n);
                break;

            case 2:
                deletefirst();
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteSpecific(value);
                break;

            case 4:
                deletelast();
                break;

            case 5:
                displayList();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice! Try again...\n");
        }
    }
    return 0;
}
