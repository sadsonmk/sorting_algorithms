#include "sort.h"

/**
 * swap_back - sorts a doubly linked list of integers
 * in ascending order
 * @list: is the list to be sorted
 * @list_p: is the list to be printed
 * Return: the sorted list.
 */
listint_t *swap_back(listint_t **list, listint_t *list_p)
{
	listint_t *ptr = *list;
	listint_t *tmp;

	while (ptr->prev)
	{
		if (ptr->n < ptr->prev->n)
		{
			tmp = ptr->prev;
			ptr->prev = tmp->prev;
			tmp->next = ptr->next;

			tmp->next->prev = tmp;
			ptr->next = tmp;
			ptr->next->prev = ptr;
			if (ptr->prev)
				ptr->prev->next = ptr;
			if (!ptr->prev)
				list_p = ptr;
			print_list(list_p);
		}
		else
			ptr = ptr->prev;
	}
	return (ptr);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * @list: is the list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = *list;
	listint_t *tmp;

	if (!list || !ptr || !ptr->next || !ptr->next->next)
		return;
	while (ptr->next)
	{
		if (ptr->n > ptr->next->n)
		{
			tmp = ptr->next;
			ptr->next = tmp->next;
			if (ptr->prev)
				ptr->prev->next = tmp;
			tmp->next = ptr;
			tmp->prev = ptr->prev;
			ptr->prev = tmp;
			if (ptr->next)
				ptr->next->prev = ptr;
			if (!tmp->prev)
				*list = tmp;
			print_list(*list);
			if (tmp->prev)
				tmp = swap_back(&tmp, *list);
			if (!tmp->prev)
				*list = tmp;
		}
		else
			ptr = ptr->next;
	}
}
