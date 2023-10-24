#include "sort.h"

/**
 * bubble_sort - Function that sorts array of ints
 * @array: The array to be sorted
 * @size: Size of the array 
 */
void bubble_sort(int *array, size_t size)
{
	size_t n = 0, t = size;
	int h;

	if (array == NULL)
		return;
	for (t = size; t > 0; t--)
	{
		for (n = 0; n < size - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				h = array[n];
				array[n] = array[n + 1];
				array[n + 1] = h;
				print_array(array, size);
			}
		}
	}
}

