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
 * bubble_sort - Sort array of integers in ascending order.
 * @array: array of integers to sort.
 * @size: size of array.
 *
 * Description: Print array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		length--;
	}
}
