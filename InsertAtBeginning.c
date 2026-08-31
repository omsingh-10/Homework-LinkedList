#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtBeginning(struct Node *head, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}

void displayList(struct Node *head)
{
    struct Node *temp = head;

    printf("Linked list after insertion: ");
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

    int value;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);

    head = insertAtBeginning(head, value);
    displayList(head);

    return 0;
}