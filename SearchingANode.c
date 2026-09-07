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

int searchNode(struct Node *head, int value)
{
	int position = 1;
	struct Node *temp = head;

	while (temp != NULL)
	{
		if (temp->data == value)
		{
			return position;
		}

		temp = temp->next;
		position++;
	}

	return -1;
}

void displayList(struct Node *head)
{
	if (head == NULL)
	{
		printf("The linked list is empty.\n");
		return;
	}

	printf("Linked list: ");
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
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
		printf("Enter 3 to search for an element:\n");
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
			printf("Enter the value to search: ");
			scanf("%d", &value);
			position = searchNode(head, value);
			if (position == -1)
			{
				printf("Value not found in the linked list.\n");
			}
			else
			{
				printf("Value found at position %d.\n", position);
			}
			break;
		case 4:
			break;
		default:
			printf("Invalid choice! Please try again.\n");
		}
	} while (choice != 4);

	return 0;
}
