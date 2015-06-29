
#include<stdlib.h>
#include<stdio.h>


int main()
{
    int a = 5;
    printf("The value of a is %d\n", a);
    int b = a << 1;
    int c = a >> 1;
    printf("A left-shift on integers is equal to multiplying by 2\n");
    printf("The value of b = a << 1 is %d\n", b);
    printf("A right-shift on integers is equal to dividing by 2\n");
    printf("The value of c = a >> 1 is %d\n", c);
    printf("\n");


    int i = 15;
    int j = 4;
    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("i & j = %d\n", i & ~j);


    exit(0);

}
