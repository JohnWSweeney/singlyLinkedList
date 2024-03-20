#include "singlyLinkedList.h"

int main()
{
	printf("singlyLinkedList v0.0.16\n\n");
	int result = 0;
	int nodeCount = 0;
	int data = 0;
	int position1 = 0;
	int position2 = 0;
	struct node* list = NULL;
	struct node* tsil = NULL;
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
	/// test code here: ////////////////////////////////////////
	
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