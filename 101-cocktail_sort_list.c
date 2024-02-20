#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap node in listint_t doubly-linked list
 *                   list of integers with node ahead of it.
 * @list: pointer to head of doubly-linked list of integers.
 * @tail: pointer to tail of doubly-linked list.
 * @shaker: pointer to current swapping node of cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpl = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmpl;
	else
		*list = tmpl;
	tmpl->prev = (*shaker)->prev;
	(*shaker)->next = tmpl->next;
	if (tmpl->next != NULL)
		tmpl->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmpl;
	tmpl->next = *shaker;
	*shaker = tmpl;
}

/**
 * swap_node_behind - Swap node in listint_t doubly-linked
 *                    list of integers with node behind it.
 * @list: pointer to head of doubly-linked list of integers.
 * @tail: pointer to tail of doubly-linked list.
 * @shaker: pointer to current swapping node of cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpl = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmpl;
	else
		*tail = tmpl;
	tmpl->next = (*shaker)->next;
	(*shaker)->prev = tmpl->prev;
	if (tmpl->prev != NULL)
		tmpl->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmpl;
	tmpl->prev = *shaker;
	*shaker = tmpl;
}

/**
 * cocktail_sort_list - Sort listint_t doubly-linked list of integers in
 *                      ascending order using cocktail shaker algorithm.
 * @list: pointer to head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
