#include <stdio.h>
#include "inSort.h"

#define SIZE 50

int main()
{
    int arr[SIZE];

    for (int i = 0; i < 50; i++)
        scanf("%d", (arr + i));

    insertion_sort(arr, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        if (i != SIZE - 1)
            printf("%d,", *(arr + i));
        else
            printf("%d", *(arr + i));
    }

    return 0;
}