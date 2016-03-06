/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

typedef struct student {
	char name[10];
	int score;
};
student* swap(student *, int, int);
void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len <= 0)
		return NULL;
	int i, j;
	for (i = len - 1; i >= 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (students[i].score>students[j].score)
				students = swap(students, i, j);
		}
	}
	return students;
}
student* swap(student *a, int i, int j)
{
	char t[10] = "\0";
	int t1, n = 0;
	while (a[i].name[n] != '\0')
	{
		t[n] = a[i].name[n];
		n++;
	}
	t[n] = '\0';
	t1 = a[i].score;
	n = 0;
	while (a[i].name[n] != '\0')
	{
		a[i].name[n] = a[j].name[n];
		n++;
	}
	a[i].name[n] = '\0';
	a[i].score = a[j].score;
	n = 0;
	while (a[i].name[n] != '\0')
	{
		a[j].name[n] = t[n];
		n++;
	}
	a[j].name[n] = '\0';
	a[j].score = t1;
	return a;
}