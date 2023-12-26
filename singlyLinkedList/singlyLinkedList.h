#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

struct node* init(int data);
int addFront(struct node** list, int data);
int addBack(struct node** list, int data);
int deleteFront(struct node** list);
int deleteBack(struct node** list);
int clear(struct node** list);
int isEmpty(struct node** list);
int size(struct node** list, int *nodeCount);
int print(struct node* list);