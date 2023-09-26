#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: the array to sort
 * @size: giving array size
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, k;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}
		if (k != i)
		{
			tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;
			print_array(array, size);
		}
	}
}
