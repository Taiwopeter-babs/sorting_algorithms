#include "sort.h"

/**
 * quick_sort_hoare - Implements the quick sort algorithm
 * @array: pointer to array to be sorted
 * @size: size of array
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recur(array, 0, size - 1, size);
}

/**
 * quick_sort_recur - recursive function repeating partitioning and sorting
 * @array: parameter array
 * @lb: lower bound of array. This changes as function is called
 * @ub: upper bound of array. Also changes as function is recursively called
 * @arr_size: size of array
 * Return: nothing
 */
void quick_sort_recur(int *array, size_t lb, size_t ub, size_t arr_size)
{
	ssize_t loc = 0;

	if (lb >= ub)
		return;

	loc = partition_hoare(array, lb, ub, arr_size);

	quick_sort_recur(array, lb, loc - 1, arr_size);
	quick_sort_recur(array, loc, ub, arr_size);
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
 * partition_hoare - separats the array elements, based on the pivot
 * element. It uses the Hoare partition - Pivot is the last element
 * to be sorted; Loop will be executed at least once.
 * @array: array or subarray, as the case may be, to be partitioned
 * @lb: index of lower bound of array or subarray
 * @ub: index of upper bound of array or subarray
 * @arr_size: size of array
 * Return: location / index of the pivot element
 */
ssize_t partition_hoare(int *array, ssize_t lb, ssize_t ub, size_t arr_size)
{
	ssize_t pivot;
	ssize_t start, end;

	start = lb - 1;
	end =  ub + 1;
	pivot = array[ub];

	while (1)
	{
		do {
			start++;
		} while (array[start] < pivot);

		do {
			end--;
		} while (array[end] > pivot);

		if (start >= end)
			return (start);
		swap_values(&array[start], &array[end]);
		print_array(array, arr_size);

	}
}
