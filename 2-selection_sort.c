#include "sort.h"

/**
 * selection_sort - implements the selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (!array || size < 2)
		return;

	/**
	 * jth index cannot exceed the array, hence set i
	 * to loop until it is 2 elements to the end of array
	 */
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (array[min_idx] > array[j])
				/* set min_idx to new min */
				min_idx = j;
			j++;
		}
		/**
		 * If the element at the current index is < element at next
		 * index, and j has reached the end of the loop,
		 * swap will not occur, continue the first iteration
		 */
		if (min_idx == i)
			continue;
		swap_values(&array[min_idx], &array[i]);
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
