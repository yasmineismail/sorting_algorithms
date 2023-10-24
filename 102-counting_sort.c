#include "sort.h"
#include <stdlib.h>

/**
 * max_arr - Max of the array
 * @array: The array
 * @size: Size of the array
 * Return: max
 */
int max_arr(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort - sorts an array using Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *arr, *o_arr, max, num;
	size_t i;

	if (size < 2 || !array)
		return;
	max = max_arr(array, size);

	arr = malloc(sizeof(size_t) * (max + 1));
	o_arr = malloc(sizeof(int) * size);

	for (i = 0; (int)i <= max; i++)
		arr[i] = 0;
	for (i = 0; i < size; i++)
	{
		num = array[i];
		arr[num] += 1;
	}
	for (i = 1; (int)i <= max; i++)
		arr[i] += arr[i - 1];
	print_array(arr, max + 1);
	for (i = 0; i < size; i++)
	{
		o_arr[arr[array[i]] - 1] = array[i];
		arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = o_arr[i];

	free(o_arr);
	free(arr);
}
