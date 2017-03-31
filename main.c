#include "student.h"
#include "accommodiation.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
	InitAccommodiation();

	SortByAge();
	ListPrint();

	SortByScoreOfC();
	ListPrint();

	SortByScoreOfAvg();
	ListPrint();

	CleanUp();
	return 0;
}
