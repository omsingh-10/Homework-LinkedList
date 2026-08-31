#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *InsertAtEnd(struct Node *head, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
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

    head = InsertAtEnd(head, 3);
    head = InsertAtEnd(head, 2);
    head = InsertAtEnd(head, 1);

    displayList(head, "Linked list before insertion: ");

    int value;
    printf("Enter value to insert at end: ");
    scanf("%d", &value);

    head = InsertAtEnd(head, value);
    displayList(head, "Linked list after insertion: ");

    return 0;
}