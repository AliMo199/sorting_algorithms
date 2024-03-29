#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Order subset of array of integers
 *                   according to hoare partition scheme.
 * @array: array of integers.
 * @size: size of array.
 * @left: starting index of subset to order.
 * @right: ending index of subset to order.
 *
 * Return: final partition index.
 *
 * Description: Uses last element of partition as pivot.
 * Prints array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement quicksort algorithm through recursion.
 * @array: array of integers to sort.
 * @size: size of array.
 * @left: starting index of array partition to order.
 * @right: ending index of array partition to order.
 *
 * Description: Uses Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int partit;

	if (right - left > 0)
	{
		partit = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, partit - 1);
		hoare_sort(array, size, partit, right);
	}
}

/**
 * quick_sort_hoare - Sort array of integers in ascending
 *                    order using quicksort algorithm.
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: Uses Hoare partition scheme. Print
 * array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
