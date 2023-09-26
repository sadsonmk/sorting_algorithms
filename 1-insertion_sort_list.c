#include "sort.h"


/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * @list: is the list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *tmp, *prev;

	if (!list || !*list)
		return;

	ptr = *list;
	while ((ptr = ptr->next))
	{
		tmp = ptr;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			prev = tmp->prev;
			if (tmp->next)
				tmp->next->prev = prev;
			if (prev->prev)
				prev->prev->next = tmp;
			else
				*list = tmp;
			prev->next = tmp->next;
			tmp->prev = prev->prev;
			tmp->next = prev;
			prev->prev = tmp;

			print_list(*list);
		}
	}
}
