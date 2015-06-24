
/*
 * Based off of Wikipedia pseudocode
 * Quicksort runs in (n log n) time on average.  This performance is
 * predicated on proper choosing of a pivot element for the algorithm.  For
 * simplicity's sake this implementation always selects the first element of
 * the subarray.  However, if the array were to be already sorted, always
 * selecting the leftmost subarray element would lead to a worst-case
 * performance of n^2. This worst-case performance is also gained through
 * sorting a list with many duplicate items.
 */

#include<stdio.h>

void printList(int list[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int list[], int lowIndex, int highIndex)
{
    int pivotIndex = lowIndex; // always choose the first element.  This is bad!
    int pivotValue = list[pivotIndex];
    int storeIndex = lowIndex;

    swap(&list[pivotIndex], &list[highIndex]);

    for (int i = lowIndex; i < highIndex; i++)
    {
        if (list[i] < pivotValue)
        {
            swap(&list[i], &list[storeIndex]);
            storeIndex++;
        }
    }

    swap(&list[storeIndex], &list[highIndex]);

    return storeIndex;
}

void quicksort(int list[], int lowIndex, int highIndex)
{
    if (lowIndex < highIndex)
    {
        int pivot = partition(list, lowIndex, highIndex);
        quicksort(list, lowIndex, pivot - 1);
        quicksort(list, pivot + 1, highIndex);
    }

}

int main()
{
    int list[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int length = sizeof(list) / sizeof(int);

    printList(list, length);
    quicksort(list, 0, length - 1);
    printf("\n");
    printList(list, length);

    return 0;

}
