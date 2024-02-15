#pragma once
#include "singlyLinkedList.h"
// sweeney's hand-rolled singly linked list.
//
// pos = "position".
// ptr = "pointer".
//
// error codes:
// 0	no error.
// 1	list is NULL.
// 2	ptr is NULL.
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

int addPos(struct node** list, int pos, int data)
{
	if (*list == NULL) return 1;

	struct node* head = *list;
	if (pos == 0) // add new head node.
	{
		struct node* newNode = malloc(sizeof(struct node));
		newNode->data = data;
		newNode->next = head;
		*list = newNode;
		return 0;
	}

	// add node after head.
	struct node* prev = head;
	*list = head->next;
	int tempPos = 1;

	while (*list != NULL)
	{
		struct node* curr = *list;
		if (pos == tempPos)
		{
			struct node* newNode = malloc(sizeof(struct node));
			newNode->data = data;
			prev->next = newNode;
			newNode->next = curr;
			*list = head;
			return 0;
		}
		prev = curr;
		*list = curr->next;
		++tempPos;
	}
	*list = head; // position not in list, reset list.
	return -1;
}

int deleteFront(struct node** list)
{
	if (*list == NULL) return 1;

	struct node* head = *list;
	*list = head->next;
	free(head);
	return 0;
}

int deleteBack(struct node** list)
{
	if (*list == NULL) return 1;

	struct node* head = *list;
	if (head->next == NULL) // check if list has only one node.
	{
		free(head);
		*list = NULL;
		return 0;
	}

	do {
		struct node* curr = *list;
		struct node* dummy = curr->next;
		if (dummy->next == NULL) // 
		{
			free(dummy);
			curr->next = NULL;
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != NULL);
}

int deletePos(struct node** list, int pos)
{
	if (*list == NULL) return 1; // list is empty.

	struct node* head = *list;
	if (pos == 0)
	{
		*list = head->next;
		free(head);
		return 0;
	}

	struct node* prev = head; // store previous node address.
	*list = head->next; // Already checked pos == 0, increment list.
	int tempPos = 1;
	do {
		struct node* curr = *list;
		if (pos == tempPos)
		{
			prev->next = curr->next;
			free(curr);
			*list = head;
			return 0;
		}
		++tempPos;
		prev = curr;
		*list = curr->next;
	} while (*list != NULL);
	*list = head; // position not in list, reset list.
	return -1;
}

int deletePtr(struct node** list, struct node* ptr)
{
	if (*list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2;

	struct node* head = *list;
	if (ptr == head)
	{
		*list = head->next;
		free(head);
		return 0;
	}

	struct node* prev = head;
	do {
		struct node* curr = *list;
		if (curr == ptr)
		{
			prev->next = curr->next;
			free(curr);
			*list = head;
			return 0;
		}
		prev = curr;
		*list = curr->next;
	} while (*list != NULL);
	*list = head; // pointer not in list, reset list.
	return -1;
}

int deleteAfterPos(struct node** list, int pos)
{
	if (*list == NULL) return 1; // list is empty.

	struct node* head = *list;

	int tempPos = 0;
	while (*list != NULL)
	{
		struct node* curr = *list;
		if (pos == tempPos)
		{
			while (curr->next != NULL)
			{
				struct node* dummy = curr->next;
				curr->next = dummy->next;
				free(dummy);
			}
			*list = head;
			return 0;
		}
		*list = curr->next;
		++tempPos;
	}
	*list = head;
	return -1; // position not in list, reset list.
}

int returnPosPtr(struct node* list, int pos, struct node** ptr)
{
	if (list == NULL) return 1; // list is empty.

	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			*ptr = list;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
	return -1;
}

int returnFrontData(struct node** list, int* data)
{
	if (*list == NULL) return 1; // list is empty.
	struct node* head = *list;
	*data = head->data;
	return 0;
}

int returnBackData(struct node* list, int* data)
{
	if (list == NULL) return 1; // list is empty.

	while (list->next != NULL)
	{
		list = list->next;
	}
	*data = list->data;
	return 0;
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

int returnDataPtr(struct node* list, int data, int* ptr) /// int ptr????
{
	if (list == NULL) return 1; // list is empty.

	do {
		if (list->data == data)
		{
			ptr = list;
			return 0;
		}
		list = list->next;
	} while (list != NULL);
	return -1; // data not in list.
}

int returnMinPos(struct node* list, int* min, int* pos)
{
	if (list == NULL) return 1; // list is empty.

	// iniitialize results with first node.
	*min = list->data;
	*pos = 0;

	list = list->next; // increment list.
	int tempPos = 1;
	do {
		if (*min > list->data)
		{
			*min = list->data;
			*pos = tempPos;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
	return 0;
}

int returnMinPtr(struct node* list, int* min, struct node** ptr)
{
	if (list == NULL) return 1; // list is empty.

	// initialize results with first node.
	*min = list->data;
	*ptr = list;

	do {
		if (*min > list->data)
		{
			*min = list->data;
			*ptr = list;
		}
		list = list->next;
	} while (list != NULL);
	return 0;
}

int returnMaxPos(struct node* list, int* max, int* pos)
{
	if (list == NULL) return 1; // list is empty.

	// iniitialize results with first node.
	*max = list->data;
	*pos = 0;

	list = list->next; // increment list.
	int tempPos = 1;
	do {
		if (*max < list->data)
		{
			*max = list->data;
			*pos = tempPos;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
	return 0;
}

int returnMaxPtr(struct node* list, int* max, struct node** ptr)
{
	if (list == NULL) return 1; // list is empty.

	// initialize results with first node.
	*max = list->data;
	*ptr = list;

	do {
		if (*max < list->data)
		{
			*max = list->data;
			*ptr = list;
		}
		list = list->next;
	} while (list != NULL);
	return 0;
}

int returnTailPos(struct node* list, int *pos)
{
	if (list == NULL) return 1; // list is empty.
	
	int tempPos = 0;
	while (list != NULL)
	{
		list = list->next;
		++tempPos;
	}
	*pos = tempPos;
	return 0;
}

int returnTailPtr(struct node* list, struct node** ptr)
{
	if (list == NULL) return 1; // list is empty.

	while (list != NULL)
	{
		*ptr = list;
		list = list->next;
	}	
	return 0;
}

int movePosFront(struct node** list, int pos)
{
	if (*list == NULL) return 1; // list is empty.

	if (pos == 0) return 2; // no action needed.

	struct node* head = *list;
	struct node* prev = head;
	struct node* curr = NULL;

	*list = head->next;
	int tempPos = 1;
	do {
		curr = *list;
		if (tempPos == pos)
		{
			prev->next = curr->next;
			curr->next = head;
			*list = curr;
			return 0;
		}
		++tempPos;
		prev = curr;
		*list = curr->next;
	} while (*list != NULL);
	*list = head; // position not in list, reset list.
	return -1;
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