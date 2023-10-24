#include "sort.h"

/**
 * partition - Array partition
 * @array: Array that will sorted
 * @first: the first position
 * @last: The last position
 * @size: The array size
 * Return: int
 */
int partition(int *array, int first, int last, size_t size)
{
	int i = first - 1, aux, j;

	for (j = first; j <= last - 1; j++)
	{
		if (array[j] < array[last])
		{
			i++;
			if (i < j)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[last])
	{
		aux = array[i + 1];
		array[i + 1] = array[last];
		array[last] = aux;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick - sorts an array of integers recursively
 * @array: Array that will sorted
 * @first: the first position
 * @last: The last position
 * @size: The array size
 */
void quick(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		quick(array, first, pivot - 1, size);
		quick(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array of integers using the Quick
 * sort algorithm in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	quick(array, 0, size - 1, size);
}
