#pragma once
#include "singlyLinkedList.h"
// sweeney's hand-rolled singly linked list.
//
// pos = "position".
// ptr = "pointer".
//
// error codes:
// 0	no error.
// 1	list is nullptr.
// 2	ptr is nullptr.
// 5	list has only one node.
// -1	pos/ptr not in list.
// -2	no action needed.

struct node* init(int data)
{
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int addFront(struct node** list, int data)
{
	if (*list == NULL)
	{
		*list = init(data);
		return 0;
	}

	struct node* head = *list;
	struct node* newHead = malloc(sizeof(struct node));
	newHead->data = data;
	newHead->next = head;
	*list = newHead;
	return 0;
}

int addBack(struct node** list, int data)
{
	if (*list == NULL)
	{
		*list = init(data);
		return 0;
	}

	struct node* head = *list;
	do {
		struct node* curr = *list;
		if (curr->next == NULL)
		{
			struct node* newNode = malloc(sizeof(struct node));
			newNode->data = data;
			newNode->next = NULL;
			curr->next = newNode;
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != NULL);
}

int deleteFront(struct node** list)
{
	if (*list == NULL) return 1;

	struct node* dummy = *list;
	struct node* head = *list;
	*list = head->next;
	free(dummy);
	return 0;
}

int deleteBack(struct node** list)
{
	if (*list == NULL) return 1;

	struct node* head = *list;
	do {
		struct node* dummy = *list;
		if (dummy->next == NULL) // check if list has only one node.
		{
			free(dummy->next);
			*list = NULL;
			return 0;
		}
		else if (dummy->next->next == NULL)
		{
			free(dummy->next->next);
			dummy->next = NULL;
			*list = head;
			return 0;
		}
		*list = dummy->next;
	} while (*list != NULL);
}

int updatePosData(struct node* list, int pos, int data)
{
	if (list == NULL) return 1;

	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			list->data = data;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
	return -1;
}

int returnDataPos(struct node* list, int data, int* pos)
{
	if (list == NULL) return 1; // list is empty.

	*pos = 0;
	do {
		if (list->data == data)
		{
			return 0;
		}
		++*pos;
		list = list->next;
	} while (list != NULL);
	return -1; // position not in list.
}

int returnDataPtr(struct node* list, int data, int* ptr)
{
	if (list == NULL) return 1; // list is empty.

	do {
		if (list->data == data)
		{
			*ptr = list;
			return 0;
		}
		list = list->next;
	} while (list != NULL);
	return -1; // data not in list.
}

int clear(struct node** list)
{
	if (*list == NULL) return 1; // list is already empty.

	do {
		struct node* dummy = *list;
		*list = dummy->next;
		free(dummy);
	} while (*list != NULL);
	return 0;
}

int isEmpty(struct node* list)
{
	if (list == NULL) return 1;
	else return 0;
}

int size(struct node* list, int *nodeCount)
{
	*nodeCount = 0;
	if (list == NULL) return 1;

	struct node* head = list;
	do {
		++*nodeCount;
		struct node* curr = list;
		list = curr->next;
	} while (list != NULL);
	return 0;
}

int print(struct node* list)
{
	if (list == NULL) return 1;

	int tempPos = 0;
	printf("#\tdata:\tlist:\t\t\tnext:\n");
	do {
		printf("%d\t%d\t%p\t%p\n", tempPos, list->data, list, list->next);
		++tempPos;
		list = list->next;
	} while (list != NULL);
	printf("\n");
	return 0;
}