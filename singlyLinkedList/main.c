#include <stdio.h>
#include "singlyLinkedList.h"

int main()
{
	printf("singlyLinkedLists v0.0.2\n\n");

	struct node *list = NULL;
	for (int i = 0; i < 9; i++)
	{
		addBack(&list, pow(i, 5));
	}
	print(list);
}