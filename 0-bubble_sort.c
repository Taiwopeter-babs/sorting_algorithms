#include "sort.h"

/**
 * bubble_sort - implements the bubble sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_values(&array[j], &array[j + 1]);
				print_array(array, size);
			}
			else
				continue;
		}
	}
}

/**
 * swap_values - swaps two values
 * @first: value 1
 * @second: value 2
 * Return: nothing
 */
void swap_values(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
