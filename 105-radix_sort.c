#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

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
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort array of integers in ascending
 *              order using radix sort algorithm.
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: Implement LSD radix sort algorithm. Print
 * array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maxim, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	maxim = get_max(array, size);
	for (sig = 1; maxim / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
