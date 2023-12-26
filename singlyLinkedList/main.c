#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* init(int data)
{
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int addBack(struct node* list, int data)
{
	if (list == NULL)
	{
		list = init(data);
		return 0;
	}

	struct node* head = list;
	do {
		struct node* curr = list;
		if (curr->next == NULL)
		{
			struct node* newNode = malloc(sizeof(struct node));
			newNode->data = data;
			newNode->next = NULL;
			curr->next = newNode;
			list = head;
			return 0;
		}
		list = list->next;
	} while (list != NULL);
}

int print(struct node* list)
{
	if (list == NULL) return 1;

	do {
		printf("list data: %d\n", list->data);
		list = list->next;
	} while (list != NULL);
	return 0;
}

int main()
{
	printf("singlyLinkedLists v0.0.0\n\n");

	struct node *list = init(1234);
	addBack(list, 4321);
	print(list);
	
	free(list);

}