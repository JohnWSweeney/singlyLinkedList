#include "support.h"

int getRandNum(int min, int max)
{
	return rand() % (max + 1 - min) + min;;
}

int populateList(struct node** list, int isRandom, int nodeNum, int min, int max)
{
	if (isRandom == 0)
	{
		for (int i = 0; i < nodeNum; i++)
		{
			int num = pow(i, 5);
			int result = addBack(list, num);
			if (result == 1) return 1;
		}
	}
	else
	{
		srand(time(NULL));
		for (int i = 0; i < nodeNum; i++)
		{
			int result = addBack(list, getRandNum(min, max));
			if (result == 1) return 1;
		}
	}
}