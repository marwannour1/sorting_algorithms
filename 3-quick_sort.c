#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: void
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;
	int i, j, temp;

	if (low < high)
	{
		pivot = high; // Change this line
		i = low;
		j = high;

		while (i < j)
		{
			while (array[i] <= array[pivot] && i < high)
				i++;
			while (array[j] > array[pivot] && j > low) // Change this line
				j--;
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}

		temp = array[pivot];
		array[pivot] = array[j];
		array[j] = temp;
		print_array(array, size);

		quick_sort_recursive(array, low, j - 1, size);
		quick_sort_recursive(array, j + 1, high, size);
	}
}
