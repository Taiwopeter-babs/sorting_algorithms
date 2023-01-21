#include "sort.h"

/**
 * shell_sort - implements shell sort algorithm with
 * Knuth's sequence
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t j, gap;
	int i;

	if (!array || size < 2)
		return;

	gap = 1;
	while (gap <= size / 3)
		gap = (gap * 3) + 1;

	while (gap >= 1)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] > array[i])
					break;

				swap_values(&array[i + gap], &array[i]);
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
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
