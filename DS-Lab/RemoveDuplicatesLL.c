#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} * new, *head, *tail, *temp;

void linkedListTraversal(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

void delete_duplicates(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2;
    while (ptr1->next != NULL)
    {
        if (ptr1->data == ptr1->next->data)
        {
            ptr2 = ptr1->next->next;
            free(ptr1->next);
            ptr1->next = ptr2;
        }
        else
        {
            ptr1 = ptr1->next;
        }
    }
}
struct Node *InsertAtEnd(struct Node *tail, int data)
{

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    tail->next = new;
    new->next = NULL;
    tail = new;
    return head;
}

// create list
int main()
{

    int value;
    char ch = 'y';
    int position;
    printf("create linked list\n");
    while (ch == 'y')
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        printf("enter value to be inserted in linked list");
        scanf("%d", &value);
        new->data = value;
        if (head == NULL)
        {
            head = new;
            tail = new;
        }
        else
        {
            tail->next = new;
            tail = new;
        }

        fflush(stdin);
        printf("y- continue, n-exit");
        scanf(" %c", &ch);
    }
    printf("enetr value to be inserted\n");
    scanf("%d", &value);
    head = InsertAtEnd(tail, value);
    printf("Linked list \n");
    linkedListTraversal(head);
    delete_duplicates(head);
    printf("\nThe updated linklist is:\n");
    linkedListTraversal(head);
    return 0;
}