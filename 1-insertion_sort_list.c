#include "sort.h"

/**
 * swap - sorts a doubly linked list of integers
 * in ascending order
 * @list: is the list to be sorted
 * @list_p: is the list to be printed
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 * Return: the sorted list.
 */
listint_t *swap(listint_t **list, listint_t *list_p)
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
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
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

	if (!ptr)
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
			print_list(*list);
			if (tmp->prev)
				tmp = swap(&tmp, *list);
			if (!tmp->prev)
				*list = tmp;
		}
		else
			ptr = ptr->next;
	}
	if (!tmp->prev)
		*list = tmp;
}
