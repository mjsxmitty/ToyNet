
#include <string.h>
#include <stdio.h>

#include "01.h"

int binary_search(const int *arr, int val)
{
    //int     mid = 0;
    int     low = 0;
    //int     high = strlen(arr) - 1;
    int       high = sizeof(arr) / sizeof(*arr);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int guess = arr[mid];

        if (guess == val)
        {
            return mid;
        }
        else if (guess > val)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}

void test_binary_search()
{
    int my_list = {1, 3, 5, 7, 9};
    printf("guess index: %d\n", binary_search(my_list, 3));
    printf("guess index: %d\n", binary_search(my_list, -1));
}