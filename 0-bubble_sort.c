#include "sort.h"

/**
 * bubble_sort - function that sorts an array
 * @array: input array
 * @size: size of the array
 * Return: no return
 */
void bubble_sort(int *array, size_t size)
{
	size_t passes = size, i;
	int temp, swapped;

	while (passes > 0)
	{
		swapped = 0;
		for (i = 0; (i + 1) < passes; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		passes--;
	}
}
