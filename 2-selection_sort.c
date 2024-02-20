#include "sort.h"

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
 * selection_sort - Sort array of integers in ascending order
 *                  using selection sort algorithm.
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: Print array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *minim;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minim = array + i;
		for (j = i + 1; j < size; j++)
			minim = (array[j] < *minim) ? (array + j) : minim;

		if ((array + i) != minim)
		{
			swap_ints(array + i, minim);
			print_array(array, size);
		}
	}
}
