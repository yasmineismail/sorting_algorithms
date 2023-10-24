#include "sort.h"
/**
* insertion_sort_list - Function sort array with insertion sort
* @list: The linked list that will sort
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tp;
	int i;

	if (!list)
		return;
	tp = *list;
	while (tp)
	{
		while (tp && tp->next)
		{
			if (tp->i > tp->next->i)
			{
				i = tp->i;
				*(int *)&tp->i = tp->next->i;
				*(int *)&tp->next->i = i;
				tp = *list;
				print_list(*list);
				break;
			}
			tp = tp->next;
		}
	}
}
