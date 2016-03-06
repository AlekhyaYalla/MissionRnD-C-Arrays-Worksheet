/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
#include<stdlib.h>

typedef struct student {
	char *name;
	int score;
};
int* max(student *, int *, student, int, int);
student ** topKStudents(struct student *students, int len, int K) {
	
	int i = 0, j = 0, *f, n = 0;
	student *b, m,**result=NULL;
	if (students == NULL || len <= 0 || K <= 0)
		return NULL;
	if (K > len)
		K = len;
	b = (student*)malloc(sizeof(student)*K);
	f = (int*)calloc(len, sizeof(int));
	while (j<K)
	{
		while (f[i] == 1)
			i++;
		n = 0;
		m.score = students[i].score;
		while (students[i].name[n] != '\0')
		{
			m.name[n] = students[i].name[n];
			n++;
		}
		m.name[n] = '\0';
		f[i] = 1;
		f = max(students, f, m, len, i);
		j++;
	}
	i = 0;
	j = 0;
	while (i<len && j<K)
	{
		if (f[i] == 1)
		{
			b[j].score = students[i].score;
			n = 0;
			while (students[i].name[n] != '\0')
			{
				b[j].name[n] = students[i].name[n];
				n++;
			}
			b[j].name[n] = '\0';
			j++;
		}
		i++;
	}
	i = 0;
	while (i < K)
	{
		b[i] = *result[i];
		i++;
	}
	return result;
}
int* max(student *a, int *f, student m, int l, int n)
{
	int i = 0, j = 0;
	while (i<l)
	{
		if (a[i].score>m.score&&f[i] != 1)
		{
			m.score = a[i].score;
			j = i;
		}
		i++;
	}
	if (j>0)
	{
		f[j] = 1;
		f[n] = 0;
	}
	return f;
}