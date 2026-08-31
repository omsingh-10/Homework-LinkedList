#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Beginning(struct Node *head, int newData)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return head;
    }
    
    newNode->data = newData;
    
    newNode->next = head;
    
    return newNode;
}

void displayList(struct Node *head, const char *message)
{
    struct Node *temp = head;

    printf("%s", message);
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value, flag = 1;
    struct Node *head = NULL;
    while (flag)
    {
        printf("Enter 1 to insert at the beginning:\nEnter 2 to display the list:\nEnter 0 to exit:\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                head = Beginning(head, value);
                break;
            case 2:
                displayList(head, "Linked list: ");
                break;
            case 0:
                flag = 0;
                break;
            default:
                printf("Invalid choice! Please try again.\n");

        }
    }  
    return 0;
}