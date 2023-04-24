#include "sort.h"

/**
 * merge_sort - Function that sorts an array w/ merge sort algorithm
 * @array: The array of integers
 * @size: The array size
 *
 * Return: None
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	top_down_merge_sort(array, buffer, 0, size);
	free(buffer);
}

/**
 * top_down_merge_sort - Function to sort buffer with recutsion
 * @array: The array of integers
 * @buffer: A copy of the array of integers
 * @top: Top index of the array
 * @down: Down index of the array
 *
 * Return: None
 */
void top_down_merge_sort(int *array, int *buffer, size_t top, size_t down)
{
	size_t i, mid;

	if (down - top > 1)
	{
		mid = top + (down - top) / 2;
		top_down_merge_sort(array, buffer, top, mid);
		top_down_merge_sort(array, buffer, mid, down);

		for (i = top, j = mid, k = 0; k < (down - top); k++)
		{
			if (i < mid && (j >= down || array[i] <= array[j]))
			{
				buffer[k] = array[i];
				i++;
			}
			else
			{
				buffer[k] = array[j];
				j++;
			}
		}

		while (i < mid)
			buffer[k++] = array[i++];

		while (j < down)
			buffer[k++] = array[j++];

		for (i = top, k = 0; i < down; i++)
			array[i] = buffer[k++];
	}
}
