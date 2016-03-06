/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>
int* move_arr(int *, int, int);
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i = 0, *p;
	if (Arr == NULL || len <= 0)
		return NULL;
	while (Arr[i]<num&&i<len)
		i++;
	if (Arr[i] >= num || i >= len)
	{
		p = &Arr[i];
		p = move_arr(p, len - i, num);
	}
	return Arr;
}
int* move_arr(int *p, int l, int n)
{
	int i, j;
	i = l;
	j = i - 1;
	while (i != 0)
	{
		p[i] = p[j];
		i--;
		j--;
	}
	p[i] = n;
	return p;
}
