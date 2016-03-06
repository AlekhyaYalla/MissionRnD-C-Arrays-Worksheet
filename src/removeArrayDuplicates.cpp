/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
int* move_arr(int *,int);
int removeArrayDuplicates(int *Arr, int len)
{
	int *p, *q, i, j, m = 0;
	if (Arr == NULL||len <= 0)
		return -1;
	p = Arr;
	for (i = 0; i<len; i++)
	{
		q = p + 1;
		for (j = i + 1; j<len; j++)
		{
			while (*p == *q)
			{
				q = move_arr(q, len - j);
				j++;
				i++;
				m++;
			}
			if (*p != *q)
				q++;
		}
		p++;
	}
	return len - m;

}
int* move_arr(int *q, int l)
{
	int i = 0, j = 1;
	while (i<l)
	{
		q[i] = q[j];
		i++;
		j++;
	}
	return q;
}

	