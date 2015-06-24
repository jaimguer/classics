
#include<stdlib.h>
#include<stdio.h>

void printList(int list[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }
}

void insertionSort(int list[], int length)
{
    for (int current = 1; current < length; current++)
    {
        int j;
        int temp = list[current];
        for (j = current; j > 0 && temp < list[j-1]; j--)
        {
            list[j] = list[j-1];
        }
        list[j] = temp;
    }
}

int main()
{
    int list[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int listLength = sizeof(list) / sizeof(int);

    printf("List before sorting: \n");
    printList(list, listLength);
    printf("\n");

    printf("List after sorting: \n");
    insertionSort(list, listLength);
    printList(list, listLength);

    return 0;
}

