#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort subarray of integers.
 * @subarr: subarray of array of integers to sort.
 * @buff: buffer to store sorted subarray.
 * @front: front index of array.
 * @mid: middle index of array.
 * @back: back index of array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement merge sort algorithm through recursion.
 * @subarr: subarray of an array of integers to sort.
 * @buff: buffer to store sorted result.
 * @front: front index of subarray.
 * @back: back index of subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t midd;

	if (back - front > 1)
	{
		midd = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, midd);
		merge_sort_recursive(subarr, buff, midd, back);
		merge_subarr(subarr, buff, front, midd, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using merge sort algorithm.
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: Implements top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
