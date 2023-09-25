#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a DLL of integers
 * @list: doubly linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list)
		return;

	current = *list;

	while (current)
	{
		temp = current->next;

		while (temp && current->n > temp->n)
		{
			/* Swap the nodes */
			if (current->prev)
				current->prev->next = temp;
			if (temp->next)
				temp->next->prev = current;

			current->next = temp->next;
			temp->prev = current->prev;
			current->prev = temp;
			temp->next = current;

			if (!temp->prev)
				*list = temp;

			if (temp->prev)
				current = temp->prev;
			
			print_list(*list);
			temp = current->next;
		}
		current = current->next;
	}
}
