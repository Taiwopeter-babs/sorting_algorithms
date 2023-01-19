#include "sort.h"
/**
 * insertion_sort_list - implement the insertion sort algorithm
 * in a doubly linked list
 * @list: pointer to head of list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *keynode;

	if (!(*list) || !list || !(*list)->next)
		return;

	curr = *list;
	while (curr != NULL)
	{
		while (curr->next && (curr->n > curr->next->n))
		{
			keynode = curr->next;
			curr->next = keynode->next;
			keynode->prev = curr->prev;

			if (curr->prev)
				curr->prev->next = keynode;
			if (keynode->next)
				keynode->next->prev = curr;
			curr->prev = keynode;
			keynode->next = curr;
			/**
			 * if keynode->prev is not NULL
			 * set curr to it; meaning keynode is the
			 * beginning of the sorted sublist, otherwise
			 * set the head of the list to keynode
			 */
			if (keynode->prev)
				curr = keynode->prev;
			else
				*list = keynode;
			print_list(*list);

		}
		curr = curr->next;
	}
}