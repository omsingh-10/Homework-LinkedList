#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *insertAtEnd(struct Node *head, int value)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

	if (newNode == NULL)
	{
		printf("Memory allocation failed!\n");
		return head;
	}

	newNode->data = value;
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

struct Node *deleteAtPosition(struct Node *head, int position)
{
	if (head == NULL || position < 1)
	{
		printf("Invalid position or the linked list is empty.\n");
		return head;
	}

	if (position == 1)
	{
		struct Node *temp = head;
		head = head->next;
		free(temp);
		return head;
	}

	struct Node *temp = head;
	for (int currentPosition = 1;
		 currentPosition < position - 1 && temp->next != NULL;
		 currentPosition++)
	{
		temp = temp->next;
	}

	if (temp->next == NULL)
	{
		printf("Position is outside the linked list.\n");
		return head;
	}

	struct Node *nodeToDelete = temp->next;
	temp->next = nodeToDelete->next;
	free(nodeToDelete);
	return head;
}

void displayList(struct Node *head)
{
	struct Node *temp = head;

	if (temp == NULL)
	{
		printf("The linked list is empty.\n");
		return;
	}

	printf("Linked list: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	int choice, value, position;
	struct Node *head = NULL;

	do
	{
		printf("\nEnter 1 to insert an element:\n");
		printf("Enter 2 to display the list:\n");
		printf("Enter 3 to delete an element:\n");
		printf("Enter 4 to exit:\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the value to insert: ");
			scanf("%d", &value);
			head = insertAtEnd(head, value);
			break;
		case 2:
			displayList(head);
			break;
		case 3:
			printf("Enter the position to delete (starting from 1): ");
			scanf("%d", &position);
			head = deleteAtPosition(head, position);
			break;
		case 4:
			break;
		default:
			printf("Invalid choice! Please try again.\n");
		}
	} while (choice != 4);

	return 0;
}
