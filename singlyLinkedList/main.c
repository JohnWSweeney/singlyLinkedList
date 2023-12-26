#include <stdio.h>
#include "singlyLinkedList.h"

int main()
{
	printf("singlyLinkedLists v0.0.3\n\n");
	int result;
	int nodeCount;

	struct node *list = NULL;
	for (int i = 0; i < 9; i++)
	{
		addBack(&list, pow(i, 5));
	}
	print(list);

	/// test code here: ////////////////////////////////////////
	result = size(&list, &nodeCount);
	printf("size result: %d\n", result);
	printf("Node count: %d\n\n", nodeCount);

	result = clear(&list);
	printf("clear result: %d\n", result);

	result = print(list);
	printf("print result: %d\n", result);
	////////////////////////////////////////////////////////////
}