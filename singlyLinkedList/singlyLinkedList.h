#pragma once
#include <stdio.h>
#include "nodes.h"
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

void init(struct node** list, int data);
int addFront(struct node** list, int data);
int addBack(struct node** list, int data);
int addPos(struct node** list, int pos, int data);
int deleteFront(struct node** list);
int deleteBack(struct node** list);
int deletePos(struct node** list, int pos);
int deletePtr(struct node** list, struct node* ptr);
int deleteBeforePos(struct node** list, int pos);
int deleteBeforePtr(struct node** list, struct node* ptr);
int deleteAfterPos(struct node** list, int pos);
int deleteAfterPtr(struct node** list, struct node* ptr);
int returnPosPtr(struct node* list, int pos, struct node** ptr);
int returnPtrPos(struct node* list, struct node* ptr, int* pos);
int returnFrontData(struct node** list, int* data);
int returnBackData(struct node* list, int* data);
int returnPosData(struct node* list, int pos, int* data);
int returnPtrData(struct node* list, struct node* ptr, int* data);
int updatePosData(struct node* list, int pos, int data);
int updatePtrData(struct node* list, struct node* ptr, int data);
int returnDataPos(struct node* list, int data, int* pos);
int returnDataPtr(struct node* list, int data, int* ptr);
int returnMinPos(struct node* list, int* min, int* pos);
int returnMinPtr(struct node* list, int* min, struct node** ptr);
int returnMaxPos(struct node* list, int* max, int* pos);
int returnMaxPtr(struct node* list, int* max, struct node** ptr);
int returnTailPos(struct node* list, int *pos);
int returnTailPtr(struct node* list, struct node** ptr);
int movePosFront(struct node** list, int pos);
int movePtrFront(struct node** list, struct node* ptr);
int movePosBack(struct node** list, int pos);
int movePtrBack(struct node** list, struct node* ptr);
int movePosUp(struct node** list, int pos);
int movePtrUp(struct node** list, struct node* ptr);
int movePosDown(struct node** list, int pos);
int movePtrDown(struct node** list, struct node* ptr);
int clear(struct node** list);
int isEmpty(struct node* list);
int size(struct node* list, int *nodeCount);
int print(struct node* list);
int reverse(struct node** list);
int swapPos(struct node** list, int pos1, int pos2);
int swapPtr(struct node** list, struct node* ptr1, struct node* ptr2);
int appendList(struct node** listA, struct node** listB);
int shuffle(struct node** list);
int bubbleSort(struct node** list, int ascending);