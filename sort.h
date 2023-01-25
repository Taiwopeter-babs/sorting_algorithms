#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* Helper functions */
void print_array(const int *array, size_t size);
void swap_values(int *first, int *second);
void print_list(const listint_t *list);
void quick_sort_part(int *array, ssize_t lb, ssize_t ub, size_t size);
ssize_t partition_array(int *array, ssize_t lb, ssize_t ub, size_t arr_size);
void shell_sort(int *array, size_t size);
void swap_node(listint_t **head, listint_t *node);

int *_memset(int *array, int *byte, size_t n);
int find_max(int *array, size_t size);

ssize_t partition_hoare(int *array, ssize_t lb, ssize_t ub, size_t arr_size);
void quick_sort_hoare(int *array, size_t size);
void quick_sort_recur(int *array, size_t lb, size_t ub, size_t arr_size);

/* Sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);

#endif /* SORT_H */
