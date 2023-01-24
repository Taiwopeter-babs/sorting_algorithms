#include "sort.h"

/**
 * quick_sort - Implements the quick sort algorithm
 * @array: pointer to array to be sorted
 * @size: size of array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_part(array, 0, size - 1, size);
}

/**
 * quick_sort_part - recursive function repeating partitioning and sorting
 * @array: parameter array
 * @lb: lower bound of array. This changes as function is called
 * @ub: upper bound of array. Also changes as function is recursively called
 * @arr_size: size of array
 * Return: nothing
 */
void quick_sort_part(int *array, ssize_t lb, ssize_t ub, size_t arr_size)
{
	ssize_t loc;

	if (lb < ub)
	{
		loc = partition_array(array, lb, ub, arr_size);

		quick_sort_part(array, lb, loc - 1, arr_size);

		quick_sort_part(array, loc + 1, ub, arr_size);
	}
}

/**
 * swap_values - swaps positions of elements in an array
 * @first: first element to be swapped
 * @second: second element to swap with first element
 * Return: nothing
 */
void swap_values(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * partition_array - separats the array elements, based on the pivot
 * element. It uses the Lomuto partition - last element in the array
 * is picked as pivot.
 * @array: array or subarray, as the case may be, to be partitioned
 * @lb: index of lower bound of array or subarray
 * @ub: index of upper bound of array or subarray
 * @arr_size: size of array
 * Return: location / index of the pivot element
 */
ssize_t partition_array(int *array, ssize_t lb, ssize_t ub, size_t arr_size)
{
	int pivot;
	ssize_t start, current;

	start = lb;
	current = lb;
	pivot = array[ub];

	for (start = lb; start < ub; start++)
	{
		/* if element <= pivot; swap occurs */
		if (array[start] <= pivot)
		{
			/**
			 * if array[start] < pivot and current == start,
			 * then swaps will occur on the same element which makes
			 * the algorithm slower
			 */
			if (current != start)
			{
				swap_values(&array[current], &array[start]);
				print_array(array, arr_size);
			}
			current++;
		}

	}
	/**
	 * swaps should only occur on different elements
	 * if current == ub, then array[ub] is the largest element
	 * thus swap should not occur
	 */
	if (current != ub)
	{
		swap_values(&array[ub], &array[current]);
		print_array(array, arr_size);
	}
	return (current);
}
