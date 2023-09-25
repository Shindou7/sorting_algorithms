#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 * @array: input array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    _quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - recursive function to perform Quick Sort
 * @array: input array
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void _quick_sort(int *array, int low, int high, int size)
{
    if (low < high)
    {
        int pivot_index = _partition(array, low, high, size);
        _quick_sort(array, low, pivot_index - 1, size);
        _quick_sort(array, pivot_index + 1, high, size);
    }
}

/**
 * _partition - function to partition the array
 * @array: input array
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: pivot index
 */
int _partition(int *array, int low, int high, int size)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }
    if (i + 1 != high)
    {
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }
    return (i + 1);
}
