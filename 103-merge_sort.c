#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print-l-r - Print left and right partitions
 * @array: The array
 * @size: Size of the second array
 * @first: Initial position
 * @mid: middle position
 */
void print-l-r(int *array, int size, int first, int mid)
{
	int k;

	printf("Merging...\n");
	printf("[left]: ");
	k = first;
	while (k < mid)
	{
		if (k != mid - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
		k++;
	}

	printf("[right]: ");
	k = mid;
	while (k < size)
	{
		if (k < size - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
		k++;
	}
}

/**
 * merge - Merge the values in the position of array
 * @array: The array
 * @size: Size of the array
 * @cpy: Copy of array
 * @first: Initial position
 * @mid: middle position
 */
void merge(int *array, int size, int first, int mid, int *cpy)
{
	int i, j, k;

	print-l-r(array, size, first, mid);

	i = first;
	j = mid;

	printf("[Done]: ");
	k = first;
	while (k < size)
	{
		if (i < mid && (j >= size || array[i] <= array[j]))
		{
			cpy[k] = array[i];
			i++;
		}
		else
		{
			cpy[k] = array[j];
			j++;
		}
		if (k < size - 1)
			printf("%d, ", cpy[k]);
		else
			printf("%d\n", cpy[k]);
		k++;
	}
}
/**
 * mergeSort - array separator
 * @cpy: copy of array
 * @first: initial position
 * @size: size of the original  array
 * @array: the original array
 */
void mergeSort(int *cpy, int first, int size, int *array)
{
	int mid;

	if (size - first < 2)
		return;

	mid = (size + first) / 2;

	mergeSort(array, first, mid, cpy);
	mergeSort(array, mid, size, cpy);

	merge(cpy, size, first, mid, array);
}
/**
 * copy_array - copy array of int
 * @arr: array src
 * @cpy: array dest
 * @size : array size
 */
void copy_array(int *arr, int *cpy, int size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		cpy[i] = arr[i];
}

/**
 * merge_sort - Sort array using the Merge sort algorithm
 * @array: Array that will be sorted
 * @size : Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *cpy;

	cpy = malloc(sizeof(int) * size - 1);

	if (cpy == NULL)
		return;

	copy_array(array, cpy, size);

	mergeSort(cpy, 0, size, array);
	free(cpy);
}
