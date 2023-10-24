#include "sort.h"

/**
 * print_array - Prints an array
 *
 * @array: The array to be printed
 * @size: Size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t len;

	len = 0;
	while (array && len < size)
	{
		if (len > 0)
			printf(", ");
		printf("%d", array[len]);
		++len;
	}
	printf("\n");
}

/**
 * print_list - Prints a list
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}

/**
 * check_list - Function to check if list is ordered
 *
 * @list: The list to be checked
 */
void check_list(const listint_t *list)
{
	while (list)
	{
		if (list->next && list->n > list->next->n)
			printf("ERROR: [%d] > [%d]\n", list->n, list->next->n);
		list = list->next;
	}
}

/**
 * check_list - Function to check if list is ordered
 *
 * @list: The list to be checked
 */
void check_array(const int *array, size_t size)
{
	size_t len;
	for (len = 0; len < size - 1; len++)
	{
		if (array[len] > array[len + 1])
			printf("ERROR: [%d] > [%d]\n", array[len], array[len + 1]);
	}
}

/**
 * rand_array - generates random int array
 *
 * @len: The length of the array
 * @max: The max size
 * 
 * Return: int
 */
int *rand_array(int len, int max)
{
	int *arr;

	arr = calloc(len, sizeof(int));
	if (!arr)
		return (NULL);
	if (!max)
		max = RAND_MAX;
	srand(time(NULL));
	while (len--)
		arr[len] = rand() % max;
	return (arr);
}
