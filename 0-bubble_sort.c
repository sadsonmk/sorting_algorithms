#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: is the array to be sorted
 * @size: is the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned long int i, j;
	int temp;

	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
}
