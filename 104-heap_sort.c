#include "sort.h"
#define parent(x) (((x) - 1) / 2)
#define leftchild(x) (((x) * 2) + 1)

/**
 * swap - Swaps two ints
 * @array: The array to be sorted
 * @size: The size of the array
 * @a: The address of the first value
 * @b: The address of the second value
 *
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
	print_array((const int *)array, size);
}

/**
 * siftdown - siftdown implementation
 * @array: The array to be sorted
 * @start: Start of the array
 * @end: End of the array
 * @size: Size of the array
 *
 */
void siftdown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, _swap, child;

	while (leftchild(root) <= end)
	{
		child = leftchild(root);
		_swap = root;
		if (array[_swap] < array[child])
			_swap = child;
		if (child + 1 <= end &&
			array[_swap] < array[child + 1])
			_swap = child + 1;
		if (_swap == root)
			return;
		swap(array, size, &array[root], &array[_swap]);
		root = _swap;
	}
}

/**
 * heap - makes heap in-place
 * @array: array to be sorted
 * @size: size of array
 */
void heap(int *array, size_t size)
{
	size_t start;

	start = parent(size - 1);
	while (start > 0)
	{
		siftdown(array, start, size - 1, size);
		start--;
	}
}
/**
 * heap_sort - Sort array using the Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 *
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;
	heap(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(array, size, &array[end], &array[0]);
		end--;
		siftdown(array, 0, end, size);
	}
}
