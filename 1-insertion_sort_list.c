#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
  listint_t *swapped, *next_swap;

  if (!list || *list)
    return;

  swapped = (*list)->next;
  while (swapped)
    {
      next_swap = swapped->next;

		while (swapped->prev != NULL && swapped->prev->n > swapped->n)
		{
			swapped->prev->next = swapped->next;
			if (swapped->next != NULL)
				swapped->next->prev = swapped->prev;
			swapped->next = swapped->prev;
			swapped->prev = swapped->next->prev;
			swapped->next->prev = swapped;
			if (swapped->prev == NULL)
				*list = swapped;
			else
			        swapped->prev->next = swapped;
			print_list(*list);
		}
		swapped = next_swap;
    }
}
