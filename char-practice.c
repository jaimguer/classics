
#include<stdlib.h>
#include<stdio.h>

int main()
{
    char x = 'a';
    printf("Char x = %c\n", x);
    printf("Incrementing a char's numerical representation takes you to the next letter\n");
    printf("Outside of the alphabet, we get special characters\n");
    printf("Char x + 1 = %c\n",  x + 1);
    printf("Char x + 25 = %c\n", x + 25);
    printf("Char x + 26 = %c\n", x + 26);

    char y = 'A';
    printf("Char y = %c\n", y);
    printf("Char y + 1 = %c\n", y + 1);
    printf("Char y + 25 = %c\n", y + 25);
    printf("Char y + 26 = %c\n", y + 26);
    printf("\n");

    printf("To figure out a character's numerical representation, cast it as an integer\n");
    printf("'a's representation is %d\n", (int) x);
    printf("'A's representation is %d\n", (int) y);

    printf("atoi converts a string representation of an integer into a pure integer.\n");
    int i;
    i = atoi("512");
    printf("%d\n", i);

    exit(0);
}
