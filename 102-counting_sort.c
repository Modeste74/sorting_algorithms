#include "sort.h"

/**
 * counting_sort - sorts using counting sort
 * @array: to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j, n;
	int *count, max, m, q;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) *(max + 1));
	if (count == NULL)
		return;
	for (m = 0; m <= max; m++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[array[j]]++;
	print_array(array, max + 1);
	n = 0;
	for (q = 0; q <= max; q++)
	{
		while (count[q] > 0)
		{
			array[n] = q;
			count[q]--;
			n++;
		}
	}
	free(count);
}
