#include "inSort.h"

void shift_element(int* arr, int i)
{    
    while (i > 0)
    {
        *(arr+i) = *(arr+i-1);
        i-- ;
    }
}
void insertion_sort(int* arr , int len)
{
    int j, temp;
    for (int i=1 ; i<len ; i++)
    {
        j = i-1 ;
        temp = *(arr+i);
        while (j >= 0 && temp < *(arr+j))
            j-- ;
        shift_element(arr+j+1, i-j-1);
        *(arr+j+1) = temp ;
    }
}