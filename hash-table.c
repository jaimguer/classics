
/*
 * Implementation of a simple hashtable using open addressing. Currently there
 * is no lookup function.
 * Hash functions are outlined in the following website:
 * http://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200101/homework10/hashfuncs.html
 */

#include<stdio.h>
/*
 * hash :: Char* -> Nat
 * hash(char* str) hashes str using the CRC algorithm presented in the above
 * website
 */
int hash(char* str)
{
    int h = 0;
    int i = 0;
    char* temp = str;
    while(*str != NULL)
    {
        int highorder = h & 0xf8000000;
        h = h << 5;
        h = h ^ (highorder >> 27);
        h = (h ^ *(str + i)) % 541;
        str++;
    }
    printf("Hash of string %s: %d\n", temp, h);

    return h;
}

/*
 * insert :: Int[]* Int Char* -> Void
 * insert(int table[], int location, char* value) inserts value into location
 * within table
 */
void insert(char* value, char* table[], int size)
{
    int slot = hash(value);
    if (table[slot] == NULL)
    {
        table[slot] = value;
    }
    else
    {
        int i = slot+1;
        while (i < size && table[i] != NULL) { i++; }
        if (i == size) { i = 0; }
        while (i < slot + 1 && table[i] != NULL) { i++; }
        if (i == slot + 1)
        {
            printf("Table is out of room!\n");
        }
        else
        {
            table[i] = value;
        }
    }
}

void printTable(char* table[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if(table[i] != NULL)
        {
            printf("%s at position %d\n", table[i], i);
        }
    }
}

void delete(char* str, char* table[])
{
    table[hash(str)] = NULL;
}

int main()
{
    int size = 541;
    char* table[size];
    for (int i = 0; i < size; i++) { table[i] = NULL; }

    char* str  = "hello";
    char* str1 = "cat";
    char* str2 = "dog";
    char* str3 = "pillow";
    char* str4 = "market";
    char* str5 = "hot dog";
    char* str6 = "running";
    char* str7 = "interview";
    char* str8 = "iphone";
    char* str9 = "soma coffee and juice bar";

    insert(str,  table, size);
    insert(str1, table, size);
    insert(str2, table, size);
    insert(str3, table, size);
    insert(str4, table, size);
    insert(str5, table, size);
    insert(str6, table, size);
    insert(str7, table, size);
    insert(str8, table, size);
    insert(str9, table, size);
    printf("\n");
    printTable(table, size);

    return 0;

}
