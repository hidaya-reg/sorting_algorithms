#include "sort.h"
/**
 * bubble_sort - sorts an array in ascending order
 * @array: array to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j = 0;

	if (array == NULL)
		return;

	for (j = size; j > 0; j--)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
