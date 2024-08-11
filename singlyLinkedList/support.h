#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
	int data;
	struct node* next;
};

int getRandNum(int min, int max);

int populateList(struct node** list, int isRandom, int nodeNum, int min, int max);