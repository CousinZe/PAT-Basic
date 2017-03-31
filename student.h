#ifndef STUDENT_H
#define STUDENT_H

typedef struct student
{
	char name[20];
	unsigned age;
	
	unsigned score_C, score_AM, score_EN;
} *Student;

#endif // student.h
