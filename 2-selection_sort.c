#include "sort.h"

/**
 * selection_sort - sorting array using sort.
 * @array: array to be sorted.
 * @size: size of array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, sort;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		sort = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[sort])
				sort = j;
		}
		if (sort != i)
		{
			temp = array[i];
			array[i] = array[sort];
			array[sort] = temp;
			print_array(array, size);
		}
	}
}
