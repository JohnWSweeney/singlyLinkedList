#include "random.h"

void seedRand()
{
	srand(time(NULL));
}

// Random number range: rand() % (max_number + 1 - minimum_number) + minimum_number
int getRandNum(int min, int max)
{
	return rand() % (max + 1 - min) + min;;
}