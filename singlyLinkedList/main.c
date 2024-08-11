#include "support.h"
#include "singlyLinkedList.h"

int main()
{
	printf("singlyLinkedList v0.0.18\n\n");
	int result = 0;
	int nodeCount = 0;
	int data = 0;
	int position1 = 0;
	int position2 = 0;
	struct node* list = NULL;
	struct node* tsil = NULL;
	struct node* ptr1 = NULL;
	struct node* ptr2 = NULL;

	result = populateList(&list, 1, 10, 0, 20);
	result = print(list);
	/// test code here: ////////////////////////////////////////
	
	printf("Result: %d\n\n", result);
	////////////////////////////////////////////////////////////
	result = print(list);
}