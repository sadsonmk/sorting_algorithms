#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

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
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int array1[] = {19, 48, 92, 71, 13, 80, 96, 99, 123, 133};
	int array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int array3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int array4[] = {-4, 5, -2, 23, 41, 1, 4, 0};
	int array5[] = {3, 1, 2, 0};
	int array6[] = {6};
	int array7[] = {2, 1};
	int array8[] = {2, 1, 3};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);

	n = sizeof(array1) / sizeof(array1[0]);

	list = create_listint(array1, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);

	n = sizeof(array2) / sizeof(array2[0]);

	list = create_listint(array2, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);

	n = sizeof(array3) / sizeof(array3[0]);
	list = create_listint(array3, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);

	n = sizeof(array4) / sizeof(array4[0]);
	list = create_listint(array4, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);

	n = sizeof(array5) / sizeof(array5[0]);
	list = create_listint(array5, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);

	n = sizeof(array6) / sizeof(array6[0]);
	list = create_listint(array6, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);

	n = sizeof(array7) / sizeof(array7[0]);
	list = create_listint(array7, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);

	n = sizeof(array8) / sizeof(array8[0]);
	list = create_listint(array8, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);

	return (0);
}
