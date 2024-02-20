#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpl;

	tmpl = *a;
	*a = *b;
	*b = tmpl;
}

/**
 * max_heapify - Turn binary tree into complete binary heap.
 * @array: array of integers representing binary tree.
 * @size: size of array/tree.
 * @base: index of base row of tree.
 * @root: root node of binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, larg;

	left = 2 * root + 1;
	right = 2 * root + 2;
	larg = root;

	if (left < base && array[left] > array[larg])
		larg = left;
	if (right < base && array[right] > array[larg])
		larg = right;

	if (larg != root)
	{
		swap_ints(array + root, array + larg);
		print_array(array, size);
		max_heapify(array, size, base, larg);
	}
}

/**
 * heap_sort - Sort array of integers in ascending
 *             order using heap sort algorithm.
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: Implements sift-down heap sort
 * algorithm. Prints array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
