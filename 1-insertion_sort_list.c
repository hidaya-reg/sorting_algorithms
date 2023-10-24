#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *tmp;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;

	while (current)
	{
		sorted = current->prev;
		tmp = current;
		while (sorted && sorted->n > tmp->n)
		{
			if (sorted->prev)
				sorted->prev->next = tmp;
			tmp->prev = sorted->prev;
			sorted->prev = tmp;
			sorted->next = tmp->next;
			tmp->next = sorted;

			if (sorted->next)
				sorted->next->prev = sorted;
			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				*list = tmp;
			tmp->next = sorted;
			sorted = tmp->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
