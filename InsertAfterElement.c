#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node* head)
{
    struct Node* temp = head;
    printf("\nLinked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insertAfter(struct Node* head, int targetValue, int newData)
{
    struct Node* temp = head;
    
    while (temp != NULL)
    {
        if (temp->data == targetValue)
        {
            struct Node* newNode = createNode(newData);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node with value %d inserted after node with value %d\n", newData, targetValue);
            return head;
        }
        temp = temp->next;
    }

    printf("Error: Node with value %d not found in the linked list!\n", targetValue);
    return head;
}

int main()
{
    struct Node* head = NULL;
    int numElements, element, newNodeValue, afterNodeValue;
    
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &numElements);
    
    if (numElements <= 0)
    {
        printf("Invalid number of elements!\n");
        return 1;
    }
    
    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < numElements; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &element);
        
        if (head == NULL)
        {
            head = createNode(element);
        }
        else
        {
            struct Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = createNode(element);
        }
    }
    
    displayList(head);
    
    printf("\nEnter the value of the new node to insert: ");
    scanf("%d", &newNodeValue);
    
    printf("Enter the value of the node after which the new node should be inserted: ");
    scanf("%d", &afterNodeValue);
    
    head = insertAfter(head, afterNodeValue, newNodeValue);

    displayList(head);
    
    struct Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}

