#include "sort.h"

/**
 * find_max - finds the maximum element in an array
 * @array: pointer to array
 * @size: size of array
 * Return: The maximum element
 */
int find_max(int *array, size_t size)
{
	int max;
	size_t i;

	i = 1;
	max = array[0];

	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

/**
 * _memset - fills an array with constant byte
 * @array: pointer to array
 * @byte: byte to fill array with
 * @n: index of array which is the limit to fill
 * Return: array
 */
int *_memset(int *array, int *byte, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		array[i] = *byte;
		i++;
	}
	return (array);
}

/**
 * counting_sort - implements the countong sort algorithm
 * @array: pointer to array
 * @size: size of the array
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int max_ele, i, k, byte = 0;
	int *counting, *new_output;
	size_t j;

	if (!array || size < 2)
		return;

	max_ele = find_max(array, size);
	k = max_ele + 1;

	/* Allocate appropriate memory */
	counting = malloc(sizeof(int) * k + 1);
	new_output = malloc(sizeof(int) * size + 1);

	_memset(counting, &byte, k);

	/**
	 * store the number of occurences of elements in original array
	 * with the element as index in `counting`
	 */
	for (j = 0; j < size; j++)
		counting[array[j]]++;

	/* Let each index, starting from 1, register the cumulative sum */
	for (i = 1; i < k; i++)
		counting[i] += counting[i - 1];
	print_array(counting, k);
	/**
	 * Tricky part: from the end, look at the original array, and find the
	 * index of the element in the counting array. Reduce element in `counting`.
	 * Assign the element in the original array to the index in the new array
	 * NOTE: USE PRE-DECREMENT. POST-DECREMENT DOES NOT GIVE A COMPLETE ARRAY!
	 */
	for (i = (int) size - 1; i >= 0; i--)
		new_output[--counting[array[i]]] = array[i];
	/* copy the new array into the original array */
	for (j = 0; j < size; j++)
		array[j] = new_output[j];
	free(counting), free(new_output);
}
