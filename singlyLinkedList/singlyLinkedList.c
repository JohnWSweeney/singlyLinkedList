#pragma once
#include "support.h"
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

int addNode(struct node** newNode, int data)
{
	struct node* temp = malloc(sizeof(struct node));
	if (temp != NULL)
	{
		temp->data = data;
		temp->next = NULL;
		*newNode = temp;
		return 0;
	}
	else
	{
		printf("Memory allocation failed.\n");
		return 1;
	}
}

int addFront(struct node** list, int data)
{
	if (*list == NULL)
	{
		struct node* newNode = NULL;
		int result = addNode(&newNode, data);
		if (result == 0)
		{
			*list = newNode;
		}
		return result;
	}

	struct node* head = *list;
	struct node* newNode = NULL;
	int result = addNode(&newNode, data);
	if (result == 0)
	{
		newNode->next = head;
		*list = newNode;
	}
	return result;
}

int addBack(struct node** list, int data)
{
	if (*list == NULL)
	{
		struct node* newNode = NULL;
		int result = addNode(&newNode, data);
		if (result == 0)
		{
			*list = newNode;
		}
		return result;
	}

	struct node* head = *list;
	while (*list != NULL)
	{
		struct node* curr = *list;
		if (curr->next == NULL)
		{
			struct node* newNode = NULL;
			int result = addNode(&newNode, data);
			if (result == 0)
			{
				curr->next = newNode;
				*list = head;
				return 0;
			}
		}
		*list = curr->next;
	}
	*list = head;
	return 1;
}

int addPos(struct node** list, int pos, int data)
{
	if (*list == NULL) // list is empty.
	{
		struct node* newNode = NULL;
		int result = addNode(&newNode, data);
		if (result == 0)
		{
			*list = newNode;
		}
		return result;
	}

	if (pos == 0) // call addFront function.
	{
		int result = addFront(list, data);
		return 8756;
	}
	// else find pos in list.
	struct node* head = *list;
	*list = head->next;
	int tempPos = 1;
	struct node* prev = head;
	while (*list != NULL)
	{
		struct node* curr = *list;
		if (pos == tempPos)
		{
			struct node* newNode = NULL;
			int result = addNode(&newNode, data);
			if (result == 0)
			{
				prev->next = newNode;
				newNode->next = curr;
			}
			*list = head;
			return result;
		}
		++tempPos;
		prev = curr;
		*list = curr->next;
	}
	*list = head; // pos not in list, reset list.
	return 1;
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
		ptr = NULL;
		return 0;
	}

	struct node* prev = head;
	do {
		struct node* curr = *list;
		if (curr == ptr)
		{
			prev->next = curr->next;
			free(curr);
			ptr = NULL;
			*list = head;
			return 0;
		}
		prev = curr;
		*list = curr->next;
	} while (*list != NULL);
	*list = head; // pointer not in list, reset list.
	return -1;
}

int deleteBeforePos(struct node** list, int pos)
{
	if (*list == NULL) return 1; // list is empty.
	if (pos == 0) return -2; // no action needed.

	struct node* head = *list; // original head node.
	struct node* curr = NULL; // current node in sweep.
	struct node* prev = head; // previous node in sweep, initialized to head.
	struct node* newHead = NULL; // new head node at pos.

	*list = head->next; // skip head node, invalid option.
	int tempPos = 1;
	while (*list != NULL) // find pos in list.
	{
		curr = *list;
		if (pos == tempPos)
		{
			newHead = curr;
			prev->next = NULL;
			break;
		}
		else if (curr->next == NULL)
		{
			*list = head; // pos not in list, reset list.
			return -1;
		}
		prev = curr;
		*list = curr->next;
		++tempPos;
	}

	curr = head; // restart list sweep with original head node.
	while (curr != NULL) // delete nodes in original list up to newHead node.
	{
		struct node* dummy = curr;
		curr = curr->next;
		free(dummy);
	}
	*list = newHead; // reset list to newHead.
	return 0;
}

int deleteBeforePtr(struct node** list, struct node* ptr)
{
	if (*list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2; // ptr is null.

	struct node* head = *list; // original head node.
	if (ptr == head) return 2; // no action needed.
	*list = head->next; // skip head node.

	struct node* curr = NULL; // current node in list sweep.
	struct node* prev = head; // previous node in list sweep, initilized to head.
	struct node* newHead = NULL; // new head node.

	while (*list != NULL) // find ptr in list.
	{
		curr = *list;
		//if (curr->next == NULL) // end of list, ptr not in list.
		//{
		//	*list = head; // reset list.
		//	return -1;
		//}
		if (curr == ptr) // found ptr in list.
		{
			newHead = curr;
			prev->next = NULL;
			curr = head; // restart list from original head node.
			while (curr != NULL) // delete nodes up to new head node.
			{
				struct node* dummy = curr;
				curr = curr->next;
				free(dummy);
			}
			*list = newHead; // reset list at new head node.
			return 0;
		}
		prev = curr;
		*list = curr->next;
	}
	*list = head; // ptr not in list, reset list.
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

int deleteAfterPtr(struct node** list, struct node* ptr)
{
	if (*list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2; // ptr is null.

	struct node* head = *list;
	while (*list != NULL)
	{
		struct node* curr = *list;
		if (curr == ptr)
		{
			if (curr->next == NULL)
			{
				*list = head; // reset list.
				return -2;  // no action needed.
			}

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
	}
	*list = head; // ptr not in list, reset list.
	return -1;
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
		list = list->next;
		++tempPos;
	} while (list != NULL);
	return -1;
}

int returnPtrPos(struct node* list, struct node* ptr, int* pos)
{
	if (list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2; // ptr is null.

	*pos = 0;
	while (list != NULL)
	{
		if (ptr == list)
		{
			return 0;
		}
		list = list->next;
		++*pos;
	}
	return -1; // ptr not in list.
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

int returnPosData(struct node* list, int pos, int* data)
{
	if (list == NULL) return 1; // list is empty.

	int tempPos = 0;
	while (list != NULL)
	{
		if (pos == tempPos)
		{
			*data = list->data;
			return 0;
		}
		list = list->next;
		++tempPos;
	}
	return -1; // pos not in list.
}

int returnPtrData(struct node* list, struct node* ptr, int* data)
{
	if (list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2; // ptr is null.

	while (list != NULL)
	{
		if (list == ptr)
		{
			*data = list->data;
			return 0;
		}
		list = list->next;
	}
	return -1; // ptr not in list.
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

int updatePtrData(struct node* list, struct node* ptr, int data)
{
	if (list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2; // ptr is null.

	while (list != NULL)
	{
		if (ptr == list)
		{
			list->data = data;
			return 0;
		}
		list = list->next;
	}
	return -1; // ptr not in list.
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

int movePtrFront(struct node** list, struct node* ptr)
{
	if (*list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2; // ptr is null.

	struct node* head = *list;
	if (ptr == head) return -2; // no action required.

	struct node* before = NULL; // node before current node.
	struct node* curr = NULL; // current node.
	while (*list != NULL)
	{
		curr = *list;
		if (ptr == curr)
		{
			before->next = curr->next;
			curr->next = head;
			*list = curr;
			return 0;
		}
		before = curr;
		*list = curr->next;
	}
	*list = head; // ptr not in list, reset list.
	return -1;
}

int movePosBack(struct node** list, int pos)
{
	if (*list == NULL) return 1; // list is empty.

	struct node* head = *list;
	struct node* prev = NULL;
	int tempPos = 0;

	while (*list != NULL)
	{
		struct node* curr = *list;
		if (pos == tempPos) // found pos node in list.
		{
			if (curr->next == NULL) // if pos is last node.
			{
				*list = head; // no action needed, reset list.
				return 0;
			}
			
			struct node* tail = curr;
			if (curr == head) // if pos is first node.
			{
				head = head->next;
			}
			else // if pos is b/w first/last nodes.
			{
				prev->next = curr->next;
			}
			while (curr->next != NULL) // find last node.
			{
				curr = curr->next;
			}
			curr->next = tail;
			tail->next = NULL;
			*list = head;
			return 0;
		}
		prev = curr;
		*list = curr->next;
		++tempPos;
	}
	*list = head; // positin not in list, reset list.
	return -1;
}

int movePtrBack(struct node** list, struct node* ptr)
{
	if (*list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2; // ptr is null.

	struct node* head = *list;
	struct node* before = NULL;
	struct node* curr = NULL;
	while (*list != NULL)
	{
		curr = *list;
		if (curr == ptr) // found ptr in list.
		{
			if (curr->next == NULL) // ptr is last node.
			{
				*list = head; // no action required, reset list.
				return -2;
			}

			struct node* tail = curr; // create tail node variable.
			while (tail->next != NULL) // find last node in list.
			{
				tail = *list;
				*list = tail->next;
			}
			if (ptr == head) // if ptr is first node.
			{
				head = head->next;
			}
			else // all other cases.
			{
				before->next = curr->next;
			}
			tail->next = ptr;
			ptr->next = NULL;
			*list = head;
			return 0;
		}
		before = curr;
		*list = curr->next;
	}
	*list = head; // ptr not in list, reset list.
	return -1;
}

int movePosUp(struct node** list, int pos)
{
	if (*list == NULL) return 1; // list is empty.
	if (pos == 0) return -2; // pos is first node, no action needed.

	struct node* head = *list;
	struct node* before = NULL; // node before prev node.
	struct node* prev = head; // node before current node.
	struct node* curr = NULL; // current node.
	struct node* after = NULL; // node after current node.
	*list = head->next; // skip head node.
	int tempPos = 1;
	
	while (*list != NULL)
	{
		curr = *list;
		if (pos == tempPos) // found pos node in list.
		{
			after = curr->next;
			if(before != NULL)
			{
				before->next = curr;
			}
			curr->next = prev;
			prev->next = after;
			if (prev == head)
			{
				head = curr;
			}
			*list = head;
			return 0;
		}
		before = prev;
		prev = curr;
		*list = curr->next;
		++tempPos;
	}
	*list = head; // pos not in list, reset list.
	return -1;
}

int movePtrUp(struct node** list, struct node* ptr)
{
	if (*list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2; // ptr is null.

	struct node* head = *list;
	if (ptr == head) return -2; // no action needed.
	*list = head->next; // skip first node.

	struct node* before = NULL;
	struct node* prev = head;
	struct node* curr = NULL;

	while (*list != NULL)
	{
		curr = *list;
		if (ptr == curr)
		{
			if (before != NULL)
			{
				before->next = curr;
			}
			prev->next = curr->next;
			curr->next = prev;
			if (prev == head)
			{
				head = curr;
			}
			*list = head;
			return 0;
		}
		before = prev;
		prev = curr;
		*list = curr->next;
	}
	*list = head; // ptr not in list, reset list.
	return -1;
}

int movePosDown(struct node** list, int pos)
{
	if (*list == NULL) return 1; // list is empty.

	struct node* head = *list;
	struct node* before = NULL; // node before current node, swapped nodes.
	struct node* curr = NULL; // current node.
	struct node* next = NULL; // node after current node.
	struct node* after = NULL; // node after swapped nodes.
	int tempPos = 0;
	while (*list != NULL)
	{
		curr = *list;
		if (pos == tempPos)
		{
			next = curr->next;
			//after = next->next;
			if (curr->next == NULL) // pos is last node, no action required.
			{
				*list = head;
				return -1;
			}
			if (before == NULL) // curr follows head node.
			{
				curr->next = next->next;
				next->next = curr;
				*list = next;
				return 0;
			}
			// all other cases.
			before->next = next;
			curr->next = next->next;
			next->next = curr;
			*list = head;
			return 0;

		}
		before = curr;
		*list = curr->next;
		++tempPos;
	}
	*list = head; // pos not in list, reset list.
	return -1;
}

int movePtrDown(struct node** list, struct node* ptr)
{
	if (*list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2; // ptr is null.

	struct node* head = *list;
	struct node* before = NULL;
	struct node* curr = NULL;
	struct node* after = NULL;

	while (*list != NULL)
	{
		curr = *list;
		if (ptr == curr)
		{
			if (curr->next == NULL) // curr is last node.
			{
				*list = head; // reset list, no action needed.
				return -2;
			}
			after = curr->next;
			if (before != NULL)
			{
				before->next = after;
			}
			curr->next = after->next;
			after->next = curr;
			if (curr == head)
			{
				head = after;
			}
			*list = head;
			return 0;
		}
		before = curr;
		*list = curr->next;
	}
	*list = head; // ptr not in list, reset list.
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
	if (list == NULL) return 1; // list is empty.

	printf("#\tdata:\tcurr:\t\t\tnext:\n");
	int tempPos = 0;
	while (list != NULL)
	{
		printf("%d\t%d\t%p\t%p\n", tempPos, list->data, list, list->next);
		++tempPos;
		list = list->next;
	}
	printf("Node count: %d\n\n", tempPos);
	return 0;
}

int reverse(struct node** list)
{
	if (*list == NULL) return 1; // list is empty.

	struct node* head = *list;
	*list = head->next;
	head->next = NULL;

	while(*list != NULL)
	{
		struct node* curr = *list;
		*list = curr->next;
		curr->next = head;
		head = curr;
	}
	*list = head;
	return 0;
}

int swapPos(struct node** list, int pos1, int pos2)
{
	if (*list == NULL) return 1; // list is empty.
	if (pos1 == pos2) return 2; // no action needed.

	struct node* head = *list;
	struct node* before = NULL; // previous node in list sweep.
	struct node* curr = NULL; // current node in list sweep.
	struct node* beforePtr1 = NULL; // node before pos1 ptr.
	struct node* ptr1 = NULL; // ptr to pos1.
	struct node* afterPtr1 = NULL; // node after pos1 ptr.
	struct node* beforePtr2 = NULL; // node before pos2 ptr.
	struct node* ptr2 = NULL; // ptr to pos2.
	struct node* afterPtr2 = NULL; // node after pos2 ptr.
	int foundPos1 = 0; 
	int foundPos2 = 0;
	int tempPos = 0;
	// find pos1 and pos2 in list.
	while (*list != NULL)
	{
		struct node* curr = *list;
		if (tempPos == pos1) // found pos1.
		{
			foundPos1 = 1;
			ptr1 = curr;
			beforePtr1 = before;
			afterPtr1 = curr->next;
			//printf("pPos1:\t%d\t%p\n", beforePtr1->data, beforePtr1);
			//printf("pos1:\t%d\t%p\n\n", ptr1->data, ptr1);
		}
		if (tempPos == pos2) // found pos2.
		{
			foundPos2 = 1;
			ptr2 = curr;
			beforePtr2 = before;
			afterPtr2 = curr->next;
			//printf("pPos2:\t%d\t%p\n", beforePtr2->data, beforePtr2);
			//printf("pos2:\t%d\t%p\n\n", ptr2->data, ptr2);
		}
		if (foundPos1 == 1 && foundPos2 == 1) break; // exit sweep early if possible.
		before = curr;
		*list = curr->next;
		++tempPos;
	}

	if (foundPos1 == 1 && foundPos2 == 1)
	{
		if (ptr1->next == ptr2)
		{
			if (beforePtr1 != NULL)
			{
				beforePtr1->next = ptr2;
			}
			else
			{
				head = ptr2;
			}
			ptr2->next = ptr1;
			ptr1->next = afterPtr2;
		}
		else if (ptr2->next == ptr1)
		{
			if (beforePtr2 != NULL)
			{
				beforePtr2->next = ptr1;
			}
			else
			{
				head = ptr1;
			}
			ptr1->next = ptr2;
			ptr2->next = afterPtr1;
		}
		else
		{
			if (beforePtr1 != NULL)
			{
				beforePtr1->next = ptr2;
			}
			else
			{
				head = ptr2;
			}
			ptr2->next = afterPtr1;
			if (beforePtr2 != NULL)
			{
				beforePtr2->next = ptr1;
			}
			else
			{
				head = ptr1;
			}
			ptr1->next = afterPtr2;
		}

		*list = head;
		return 0;
	}
	else
	{
		*list = head; // pos1 and/or pos2 not in list, reset list.
		return -1;
	}
}

int swapPtr(struct node** list, struct node* ptr1, struct node* ptr2)
{
	if (*list == NULL) return 1; // list is empty.
	if (ptr1 == NULL || ptr2 == NULL) return 2; // ptr is null.
	if (ptr1 == ptr2) return -2; // no action needed.

	struct node* head = *list;

	struct node* before = NULL; // node before current node in sweep.
	struct node* curr = *list; // current node in sweep.
	struct node* before1 = NULL; // node before ptr1.
	struct node* after1 = NULL; // node after ptr1.
	struct node* before2 = NULL; // node before ptr2.
	struct node* after2 = NULL; // node after ptr2.
	int foundPtr1 = 0; // flag indicating ptr1 found in list.
	int foundPtr2 = 0; // flag indicating ptr2 found in list.

	while (*list != NULL) // find ptr1/ptr2 in list.
	{
		curr = *list;
		if (curr == ptr1) // found ptr1 in list.
		{
			foundPtr1 = 1;
			before1 = before;
			after1 = curr->next;
		}
		if (curr == ptr2) // found ptr2 in list.
		{
			foundPtr2 = 1;
			before2 = before;
			after2 = curr->next;
		}
		before = curr;
		*list = curr->next;
	}

	if (foundPtr1 > 0 && foundPtr2 > 0) // ptr1 and ptr2 found in list.
	{
		if (ptr1->next == ptr2) // ptr2 follows ptr1 in list.
		{
			if (before1 != NULL)
			{
				before1->next = ptr2;
			}
			ptr2->next = ptr1;
			ptr1->next = after2;
		}
		else if (ptr2->next == ptr1) // ptr1 follows ptr2 in list.
		{
			if (before2 != NULL)
			{
				before2->next = ptr1;
			}
			ptr1->next = ptr2;
			ptr2->next = after1;
		}
		else
		{
			if (before1 != NULL)
			{
				before1->next = ptr2;
			}
			ptr2->next = after1;
			if (before2 != NULL)
			{
				before2->next = ptr1;
			}
			ptr1->next = after2;
		}

		// verify head node.
		if (before1 == NULL) // ptr 1 is original head.
		{
			head = ptr2;
		}
		else if (before2 == NULL) // ptr 2 is original head.
		{
			head = ptr1;
		}
		*list = head;
		return 0;
	}
	else // ptr1 and/or ptr2 not found in list.
	{
		*list = head; // reset list.
		return -1;
	}
}

int shuffle(struct node** list)
{
	if (*list == NULL) return 1; // list is empty.

	int nodeCount = 0;
	size(*list, &nodeCount);

	int position1 = 0; 
	int position2 = 0;
	struct node* ptr1 = NULL;
	struct node* ptr2 = NULL;
	int temp = 0; // dummy counter.
	srand(time(NULL));
	do {
		position1 = getRandNum(0, nodeCount - 1); // get random list position.
		do {
			position2 = getRandNum(0, nodeCount - 1);
		} while (position1 == position2); // get second, different random list position.
		returnPosPtr(*list, position1, &ptr1); // get pointer to first position.
		returnPosPtr(*list, position2, &ptr2); // get pointer to second position.
		swapPtr(list, ptr1, ptr2); // swap list positions.
		++temp;
	} while (temp < pow(nodeCount, 2)); // repeat nodeCount^2 times.
	return 0;
}

int appendList(struct node** listA, struct node** listB)
{
	if (*listA == NULL || *listB == NULL) return 1; // list A and/or B empty.
	if (*listA == *listB) return -2; // no action needed.

	struct node* headA = *listA;
	struct node* headB = *listB;
	// find last node in listA, connect to listB head node.
	while (*listA != NULL)
	{
		struct node* curr = *listA;
		if (curr->next == NULL) // found list node in listA.
		{
			curr->next = headB;
			*listA = headA;
			*listB = NULL;
			return 0;
		}
		*listA = curr->next;
	}
}

int bubbleSort(struct node** list, int ascending)
{
	if (*list == NULL) return 1; // list is empty.

	struct node* head = *list;
	struct node* before = NULL;
	struct node* curr = *list;
	struct node* after = NULL;
	int swaps = 0;
	int swapCount = 0;
	// sweep list, sorting adjacent nodes according to ascending, until no sorts occur in a sweep.
	do {
		swaps = 0; 
		while (curr->next != NULL)
		{
			after = curr->next;
			if (ascending != 0) // sort ascending.
			{
				if (curr->data > after->data)
				{
					if (before == NULL) // curr is head node.
					{
						head = after; // update head node.
					}
					else // curr is not head node.
					{
						before->next = after;
					}
					curr->next = after->next;
					after->next = curr;
					before = after;
					*list = curr;
					++swaps;
				}
				else
				{
					before = curr;
					curr = curr->next;
				}
			}
			else // sort descending.
			{
				if (curr->data < after->data)
				{
					if (before == NULL) // curr is head node.
					{
						head = after; // update head node.
					}
					else // curr is not head node.
					{
						before->next = after;
					}
					curr->next = after->next;
					after->next = curr;
					before = after;
					*list = curr;
					++swaps;
				}
				else
				{
					before = curr;
					curr = curr->next;
				}
			}
		}
		swapCount += swaps;
		// reset list, variables.
		before = NULL;
		*list = head;
		curr = *list;	
	} while (swaps != 0);
	printf("swapCount: %d\n", swapCount);
	return 0;
}