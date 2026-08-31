#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtBeginning(struct Node *head, int newData)
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
    struct Node *head = NULL;

    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    displayList(head, "Linked list before insertion: ");

    int value;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);

    head = insertAtBeginning(head, value);
    displayList(head, "Linked list after insertion: ");

    return 0;
}