#include "sort.h"

/**
 * quick_sort - sort a list of integers using quicksort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	my_quick_sort(array, 0, size - 1, size);
}

/**
 * swap - swap two integers
 * @a: the first integer to be swapped
 * @b: the second integer to be swapped
 */
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * partition - partition an array
 * @arr: the array to be partitioned
 * @low: the start of the array
 * @high: the end of the array
 * Return: an integer
 */
int partition(int *arr, int low, int high)
{
	int pivot, i, j;

	pivot = arr[high];
	i = (low - 1);
	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/**
 * my_quick_sort - the real implementation of quicksort
 * @arr: the array to be sorted
 * @low: the beginning of the array
 * @high: the end of the array
 * @size: the size of the array
 */
void my_quick_sort(int *arr, int low, int high, int size)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		print_array(arr, size);
		my_quick_sort(arr, low, pi - 1, size);
		my_quick_sort(arr, pi + 1, high, size);
	}
}
