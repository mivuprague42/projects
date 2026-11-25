#include <stdio.h>

void my_sort(int *arr, int left, int right)
{
    if (left >= right)
        return;

    int pivot = arr[(left + right) / 2];

    for (int i = 0; i < left; i++)
    {
        printf("   ");
    }

    for (int i = left; i <= right; i++)
    {
        if (arr[i] == pivot)
            printf("\033[31m%2d\033[0m ", arr[i]);
        else
            printf("%2d ", arr[i]);
    }
    putchar('\n');

    int i = left;
    int j = right;

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }

    }
    for (int i = 0; i < left; i++)
    {
        printf("   ");
    }

    for (int i = left; i <= right; i++)
    {
        if (arr[i] == pivot)
            printf("\033[31m%2d\033[0m ", arr[i]);
        else
            printf("%2d ", arr[i]);
    }
    putchar('\n');
    putchar('\n');
    my_sort(arr, left, j);
    my_sort(arr, i, right);
}

void ft_sort_int_tab(int *tab, int size)
{
    my_sort(tab, 0, size - 1);
    return;
}



int main(void)
{
	int arr[] = {5, 9, 1, 2, 10, 15, 6, 7 , 12, 4};
	int size = 10;

	ft_sort_int_tab(arr, size);
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	putchar('\n');

	return 0;
}
