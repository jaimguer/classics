
#include<stdio.h>
#include<string.h>

void reverse(char* str, char revString[], int strLength)
{
    int last = strLength - 1;
    for (int i = 0; i <= last; i++)
    {
        revString[i] = str[last - i];
    }
}

int main()
{
    char* str = "I love cats and dogs and bikes";
    int strLength = strlen(str);
    char revString[strLength];
    reverse(str, revString, strLength);
    printf("%s\n", revString);
    return 0;
}

