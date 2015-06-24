#include<stdlib.h>
#include<stdio.h>

struct node {
    int data;
    struct node* next;
};

/*
 * initializeList :: () -> node*
 * Creates a linked list of three nodes and * returns a pointer to the head of
 * the list
*/
struct node* initializeList()
{
    struct node* first  = malloc(sizeof(struct node));
    struct node* second = malloc(sizeof(struct node));
    struct node* third  = malloc(sizeof(struct node));

    first->data  = 1;
    second->data = 2;
    third->data  = 3;

    first->next  = second;
    second->next = third;
    third->next  = NULL;

    return first;
}

/*
 * printList :: node* -> IO
 * Takes a pointer to a linked list and prints out * the entire list
*/
void printList(struct node* head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

/*
 * searchFor  :: Int Node* -> IO
 * searchFor(key, head) searches the list head for the integer key
 */
void searchFor(int key, struct node* head)
{
    int found = 0;
    while (head != NULL && !found)
    {
        if (head->data == key)
        {
            found = 1;
        }
        head = head->next;
    }
    if (found) printf("key found\n");
    if (!found) printf("key not found\n");
}


int main()
{
    struct node* head = initializeList();
    printList(head);
    searchFor(2, head);
    searchFor(12, head);
    return 0;
}
