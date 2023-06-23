#include "sort.h"

/**
 * selection_sort - sorts using selction sort method
 * @array: to be sorted
 * @size: size of array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, srt;
	int temp;

	while (i < size - 1)
	{
		srt = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[srt])
				srt = j;
		}
		if (srt != i)
		{
			temp = array[i];
			array[i] = array[srt];
			array[srt] = temp;
			print_array(array, size);
		}
		i++;
	}
}
