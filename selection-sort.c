
#include<stdlib.h>
#include<stdio.h>

void printList(int list[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }
}

int smallestIndex(int list[], int length, int start)
{
    int smallestIndex = start;
    for (int current = start + 1; current < length; current++)
    {
        if (list[current] < list[smallestIndex])
        {
            smallestIndex = current;
        }
    }
    return smallestIndex;
}

void selectionSort(int list[], int length)
{
    for (int current = 0; current < length - 1; current++)
    {
        int smallestPos   = smallestIndex(list, length, current);
        int temp          = list[smallestPos];
        list[smallestPos] = list[current];
        list[current]     = temp;
    }
}

int main()
{
    int list[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int length = sizeof(list) / sizeof(int);

    printf("Initial list:\n");
    printList(list, length);
    printf("\n");
    printf("Smallest index: %d", smallestIndex(list, length, 0));
    printf("\n");

    printf("Sorted list:\n");
    selectionSort(list, length);
    printList(list, length);

    return 0;
}
