#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
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

struct node* init(int data);
int addFront(struct node** list, int data);
int addBack(struct node** list, int data);
int deleteFront(struct node** list);
int deleteBack(struct node** list);
int updatePosData(struct node* list, int pos, int data);
int returnDataPos(struct node* list, int data, int* pos);
int returnDataPtr(struct node* list, int data, int* ptr);
int clear(struct node** list);
int isEmpty(struct node* list);
int size(struct node* list, int *nodeCount);
int print(struct node* list);