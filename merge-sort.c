
#include<stdlib.h>
#include<stdio.h>

void printList(int list[], int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d ", list[i]);
    }
}

void merge(int a[], int b[], int c[], int aSize, int bSize)
{
    int aRunner = 0;
    int bRunner = 0;
    int cRunner = 0;

    // merge until one array or the other is exhausted
    while (aRunner < aSize && bRunner < bSize) {
        if (a[aRunner] < b[bRunner]) {
            c[cRunner] = a[aRunner];
            aRunner++;
        }
        else {
            c[cRunner] = b[bRunner];
            bRunner++;
        }
        cRunner++;
    }

    // b was exhausted first
    if (aRunner < aSize) {
        while (aRunner < aSize) {
            c[cRunner] = a[aRunner];
            aRunner++;
            cRunner++;
        }
    }
    else {
        while (bRunner < bSize) {
            c[cRunner] = b[bRunner];
            bRunner++;
            cRunner++;
        }
    }
}

void mergeSort(int list[], int length)
{
    if (length == 1) {
        return;
    }
    else
    {
        int leftSize  = length / 2;
        int rightSize = length - leftSize;

        int* left  = malloc(sizeof(int) * leftSize);
        int* right = malloc(sizeof(int) * rightSize);

        for (int i = 0; i < leftSize; i++){
            left[i] = list[i];
        }
        for (int i = 0; i < rightSize; i++){
            right[i] = list[i + leftSize];
        }

        mergeSort(left, leftSize);
        mergeSort(right, rightSize);
        merge(left, right, list, leftSize, rightSize);
    }
}


int main()
{
    int list[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int length = sizeof(list) / sizeof(int);

    mergeSort(list, length);
    printList(list, length);
    return 0;
}
