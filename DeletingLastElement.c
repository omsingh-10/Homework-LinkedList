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

struct Node *deleteLast(struct Node *head)
{
	if (head == NULL)
	{
		printf("The linked list is empty.\n");
		return NULL;
	}

	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}

	struct Node *temp = head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}

	free(temp->next);
	temp->next = NULL;
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
	int choice, value;
	struct Node *head = NULL;

	do
	{
		printf("\nEnter 1 to insert an element:\n");
		printf("Enter 0 to delete the last element:\n");
		printf("Enter 2 to display the list:\n");
		printf("Enter 3 to exit:\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the value to insert: ");
			scanf("%d", &value);
			head = insertAtEnd(head, value);
			break;
		case 0:
			head = deleteLast(head);
			break;
		case 2:
			displayList(head);
			break;
		case 3:
			break;
		default:
			printf("Invalid choice! Please try again.\n");
		}
	} while (choice != 3);

	return 0;
}
