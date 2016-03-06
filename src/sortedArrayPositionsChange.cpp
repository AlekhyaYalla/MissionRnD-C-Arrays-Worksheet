/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
int* swap(int*, int, int);
void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i = 0, j = len - 1;
	if (Arr == NULL||len<=0)
		return NULL;
	while (Arr[i]<Arr[i + 1] && i<j)
		i++;
	if (i == j)
		return Arr;
	while (Arr[j]>Arr[j - 1] && j>i)
		j--;
	Arr = swap(Arr, i, j);
	return Arr;
}
int* swap(int *a, int i, int j)
{
	int t;
	t = a[i];
	a[i] = a[j];
	a[j] = t;
	return a;
}