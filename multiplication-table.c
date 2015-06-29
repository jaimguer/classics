
#include<stdio.h>


#define MAX 12

int main()
{
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = 1; j <= MAX; j++)
        {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    return 0;
}


