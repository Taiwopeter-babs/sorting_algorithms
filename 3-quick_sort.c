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
 * @arr: parameter array
 * @lb: lower bound of array. This changes as function is called
 * @ub: upper bound of array. Also changes as function is recursively called
 * Return: nothing
 */
void quick_sort_part(int *array, size_t lb, size_t ub, size_t arr_size)
{
	size_t loc;

	if (lb < ub)
	{
		loc = partition_array(array, lb, ub, arr_size);

		if (loc > 0)
		{
			quick_sort_part(array, lb, loc - 1, arr_size);
		}

		quick_sort_part(array, loc + 1, ub, arr_size);
	}

	return;
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
 * @arr: array or subarray, as the case may be, to be partitioned
 * @lb: index of lower bound of array or subarray
 * @ub: index of upper bound of array or subarray
 * Return: location / index of the pivot element
 */
size_t partition_array(int *array, size_t lb, size_t ub, size_t arr_size)
{
	int pivot;
	size_t start, end;

	start = lb;
	end =  lb;
	pivot = array[ub];

	while (end < ub)
	{
		/* if element <= pivot; swap occurs */
		if (array[end] <= pivot)
		{
			swap_values(&array[end], &array[start]);
			print_array(array, arr_size);
			/* increment the pointer on the element > pivot */
			start++;
		}
		/* increment the pointer on the element <= pivot */
		end++;
	}

	/**
	 * arr[start] is > arr[ub], since start is on the element > pivot
	 * hence, moves the pivot element to the 'center' of the partitioned
	 * array [ elements < pivot | pivot | elements > pivot ]
	 */
	swap_values(&array[ub], &array[start]);
	print_array(array, arr_size);
	return (start);
}
