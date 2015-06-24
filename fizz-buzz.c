
#include<stdio.h>

void lame()
{
    for (int i = 1; i < 100; i++)
    {
        if (! (i % 15))
        {
            printf("FizzBuzz ");
        }
        else if (! (i % 3))
        {
            printf("Fizz ");
        }
        else if (! (i % 5))
        {
            printf("Buzz ");
        }
        else
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    for (int i = 1; i < 100; i++)
    {
        if (i % 15 == 0)
        {
            printf("FizzBuzz ");
        }
        else if (i % 3 == 0)
        {
            printf("Fizz ");
        }
        else if (i % 5 == 0)
        {
            printf("Buzz ");
        }
        else
        {
            printf("%d ", i);
        }
    }
    return 0;
}
