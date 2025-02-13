#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int d;
    struct node *n;
};
struct node *head = NULL;
void insert(int data, int n) 
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (head==NULL) {
        head=temp;
        return;
    }
    temp->d = data;
    temp->n = head;
    head = temp;
}
void del(int pos) {
    if (head == NULL) { 
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node *temp = head, *prev = NULL;
    if (pos == 1) {
        head = head->n;
        free(temp);
        return;
    }
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->n;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    prev->n = temp->n;
    free(temp);
}
void display() {
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->d);
        temp = temp->n;
    }
    printf("NULL\n");
}
int main() {
    int i, n, pos, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(data);
    }
    printf("Original ");
    display();
    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);
    del(pos);
    printf("After Deletion ");
    display();
    return 0;
}