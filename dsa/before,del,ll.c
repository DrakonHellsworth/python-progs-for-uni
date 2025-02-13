// delete a node from a linked list before a node pointer x
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int main()
{
    int n;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data for node %d: ", i + 1);
        int data;
        scanf("%d", &data);
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = head;
        head = new;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nEnter the value of x: ");
    int x;
    scanf("%d", &x);
    struct node *prev = NULL;
    while (temp != NULL && temp->data != x)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node not found in the linked list.\n");
    }
    else
    {
        if (prev == NULL)
        {
            head = head->next;
        }
        else
        {
            prev->next = temp->next;
        }
        free(temp);
        printf("Linked list after deletion: ");
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    return 0;
}