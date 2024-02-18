#include <stdio.h>
#include "singlyLinkedList.h"

int main()
{
	printf("singlyLinkedList v0.0.11\n\n");
	int result = 0;
	int nodeCount = 0;
	int data = 0;
	int position = 0;
	struct node* list = NULL;
	struct node* ptr1 = NULL;
	struct node* ptr2 = NULL;

	for (int i = 0; i < 9; i++)
	{
		addBack(&list, pow(i, 4));
	}
	result = size(list, &nodeCount);
	if (result == 0)
	{
		printf("Node count: %d\n", nodeCount);
		print(list);
	}
	else
	{
		printf("List is empty.\n\n");
	}
	/// test code here: ////////////////////////////////////////
	position = 3;
	result = returnPosPtr(list, position, &ptr1);
	printf("Result: %d\n", result);
	if (result == 0)
	{
		printf("Ptr1:\t%d\t%p\n\n", ptr1->data, ptr1);
	}
	else
	{
		printf("Position 1 not in list.\n\n");
	}
	////////////////////////////////////////////////////////////
	position = 5;
	result = returnPosPtr(list, position, &ptr2);
	printf("Result: %d\n", result);
	if (result == 0)
	{
		printf("Ptr2:\t%d\t%p\n\n", ptr2->data, ptr2);
	}
	else
	{
		printf("Position 2 not in list.\n\n");
	}
	////////////////////////////////////////////////////////////
	result = swap(&list, ptr1, ptr2);
	printf("Result: %d\n\n", result);
	////////////////////////////////////////////////////////////
	result = size(list, &nodeCount);
	if (result == 0)
	{
		printf("Node count: %d\n", nodeCount);
		print(list);
	}
	else
	{
		printf("List is empty.\n\n");
	}
}