#include "sort.h"
/**
 * bubble_sort - sorts an array in ascending order
 * @array: array to sort
 * @size: size of array
 * Return: sorted array
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j = 0;

	while (j < size)
	{
		for (i = 0; i < size - j; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
			else
				continue;
		}
		j++;
	}
}
