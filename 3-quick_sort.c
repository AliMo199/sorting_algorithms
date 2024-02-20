#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpl;

	tmpl = *a;
	*a = *b;
	*b = tmpl;
}

/**
 * lomuto_partition - Order subset of array of integers according to
 *                    lomuto partition scheme (last element as pivot).
 * @array: array of integers.
 * @size: size of array.
 * @left: starting index of subset to order.
 * @right: ending index of subset to order.
 *
 * Return: final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implementation of quicksort algorithm through recursion.
 * @array: array of integers to sort.
 * @size: size of array.
 * @left: starting index of array partition to order.
 * @right: ending index of array partition to order.
 *
 * Description: Uses Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partit;

	if (right - left > 0)
	{
		partit = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partit - 1);
		lomuto_sort(array, size, partit + 1, right);
	}
}

/**
 * quick_sort - Sort array of integers in ascending
 *              order using quicksort algorithm.
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: Uses Lomuto partition scheme. Prints
 *              array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
