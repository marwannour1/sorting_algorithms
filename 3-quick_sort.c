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
	int pos;

	if (low < high)
	{
		partition(array, low, high, &pos, size);
		quick_sort_recursive(array, low, pos - 1, size);
		quick_sort_recursive(array, pos + 1, high, size);
	}
}

/**
 * partition - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @low: low index
 * @high: high index
 * @pos: position
 * @size: size of the array
 * Return: void
 */
void partition(int *array, int low, int high, int *pos, size_t size)
{
	int pivot, left, right, temp;

	pivot = array[high];
	left = low;
	right = high;

	while (left < right)
	{
		while (array[left] < pivot)
			left++;
		while (array[right] >= pivot)
			right--;
		if (left < right)
		{
			temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			print_array(array, size);
		}
	}
	temp = array[left];
	array[left] = array[high];
	array[high] = temp;
	print_array(array, size);
	*pos = left;
}
