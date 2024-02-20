#include "sort.h"

/**
 * get_max - Get maximum value in array of integers.
 * @array: array of integers.
 * @size: size of array.
 *
 * Return: maximum integer in array.
 */
int get_max(int *array, int size)
{
	int maxim, i;

	for (maxim = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maxim)
			maxim = array[i];
	}

	return (maxim);
}

/**
 * counting_sort - Sort array of integers ascending order
 *                 using counting sort algorithm.
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: Print counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maxim, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maxim = get_max(array, size);
	count = malloc(sizeof(int) * (maxim + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (maxim + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (maxim + 1); i++)
		count[i] += count[i - 1];
	print_array(count, maxim + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
