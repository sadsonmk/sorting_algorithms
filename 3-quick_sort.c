#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in
 * ascending order using Quick sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot_idx;

	if (!array || size < 2)
		return;
}