#include <stdio.h>
#include "singlyLinkedList.h"

int main()
{
	printf("singlyLinkedList v0.0.6\n\n");
	int result = 0;
	int nodeCount = 0;
	int data = 0;
	int position = 0;
	struct node* list = NULL;
	struct node* ptr = NULL;

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
	position = 0;
	result = movePosFront(&list, position);
	printf("Result: %d\n", result);
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