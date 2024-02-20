#include <stdio.h>
#include "sort.h"

/**
 * print_list - Print list of integers
 *
 * @list: list to be printed
 */
void print_list(const listint_t *list)
{
	int n;

	n = 0;
	while (list)
	{
		if (n > 0)
			printf(", ");
		printf("%d", list->n);
		++n;
		list = list->next;
	}
	printf("\n");
}
