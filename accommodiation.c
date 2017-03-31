#include "accommodiation.h"
#include "student.h"

#include <stdio.h>
#include <stdlib.h>

static Student *roommates;
static unsigned roommate_count;

static void InitStudent(Student st)
{
	scanf("%s%u%u%u%u",
			st->name,
			&(st->age),
			&(st->score_C),
			&(st->score_AM),
			&(st->score_EN));	
}

void InitAccommodiation()
{
	scanf("%u", &roommate_count);

	roommates = (Student*)malloc((roommate_count) * sizeof(Student));

	for (size_t i = 0; i < roommate_count; i++)
	{
		roommates[i] = (Student)malloc(sizeof(struct student));
		InitStudent(roommates[i]);
	}
}

void CleanUp()
{
	for (size_t i = 0; i < roommate_count; i++)
	{
		free(roommates[i]);
	}

	free(roommates);
}

void ListPrint(void)
{
	printf("%20s%10s%10s%10s%10s\n",
			"name",
			"age",
			"C score",
			"AM score",
			"ENG score");

	for (size_t i = 0; i < roommate_count; i++)
	{
		printf("%20s%10d%10d%10d%10d\n",
				roommates[i]->name,
				roommates[i]->age,
				roommates[i]->score_C,
				roommates[i]->score_AM,
				roommates[i]->score_EN);
	}
}

static int predicate_by_age(const void *a, const void *b)
{
	const Student stu_a = *(const Student*)a,
				stu_b = *(const Student*)b;

	return (stu_a->age) > (stu_b->age);
}

static int predicate_by_score_of_C(const void *a, const void *b)
{
	const Student stu_a = *(const Student*)a,
				stu_b = *(const Student*)b;
	return (stu_a->score_C) > (stu_b->score_C);
}

static int predicate_by_avg_score(const void *a, const void *b)
{
	const Student stu_a = *(const Student*)a,
				stu_b = *(const Student*)b;

	int sum_a = stu_a->score_C + stu_a->score_EN + stu_a->score_AM,
		sum_b = stu_b->score_C + stu_b->score_EN + stu_b->score_AM;

	return sum_a > sum_b;
}

void SortByAge()
{
	qsort(roommates, roommate_count, sizeof(Student), predicate_by_age);
}

void SortByScoreOfC()
{
	qsort(roommates, roommate_count, sizeof(Student), predicate_by_score_of_C);
}

void SortByScoreOfAvg()
{
	qsort(roommates, roommate_count, sizeof(Student), predicate_by_avg_score);
}

