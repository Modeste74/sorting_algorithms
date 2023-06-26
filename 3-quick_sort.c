#include "sort.h"

/**
 * swap_element - swaps the elements
 * @a: to be swapped
 * @b: to be swapped
 *
 * Return: nothing
 */
void swap_element(int *a, int *b)
{
	int temp;

	temp  = *a;
	*a = *b;
	*b = temp;
}
/**
 * partitioning - partitions using lomunto
 * @array: array to be partitioned
 * @low: starting index
 * @high: ending index
 * @size: size of array
 *
 * Return: pivot index
 */
int partitioning(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_element(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > pivot)
	{
		swap_element(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quick_sort_recursive - recursive part of quick sort
 * @array: array to undergo recursion
 * @low: starting index
 * @high: ending index
 * @size: size of array
 *
 * Return: nothing
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partitioning(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}
/**
 * quick_sort - sorts using quick sort method
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
