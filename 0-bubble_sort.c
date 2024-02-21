#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm while printing the array after each swap
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    unsigned short changed = 0;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        changed = 0;

        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                print_array(array, size);
                changed = 1;
            }
        }
        if (changed == 0)
            break;
    }
}
