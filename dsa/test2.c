#include <stdio.h>
#include <stdlib.h>
struct node {
    int coef;
    int exp;
    struct node *next;
};
struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;
void insert1(int coef, int exp) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->coef = coef;
    new->exp = exp;
    new->next = NULL;
    if(head1 == NULL)
        head1 = new;
    else {
        struct node *temp = head1;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}
void insert2(int coef, int exp) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->coef = coef;
    new->exp = exp;
    new->next = NULL;
    if(head2 == NULL)
        head2 = new;
    else {
        struct node *temp = head2;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}
void appendResult(int coef, int exp) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->coef = coef;
    new->exp = exp;
    new->next = NULL;
    if(head3 == NULL)
        head3 = new;
    else {
        struct node *temp = head3;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}
void add() {
    struct node *temp1 = head1, *temp2 = head2;
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->exp == temp2->exp) {
            appendResult(temp1->coef + temp2->coef, temp1->exp);
            temp1 = temp1->next; temp2 = temp2->next;
        } else if(temp1->exp > temp2->exp) {
            appendResult(temp1->coef, temp1->exp);
            temp1 = temp1->next;
        } else {
            appendResult(temp2->coef, temp2->exp);
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL) { appendResult(temp1->coef, temp1->exp); temp1 = temp1->next; }
    while(temp2 != NULL) { appendResult(temp2->coef, temp2->exp); temp2 = temp2->next; }
}
void display(struct node *head) {
    struct node *temp = head;
    while(temp != NULL) {
        if(temp->next != NULL)
            printf("%d*x^%d + ", temp->coef, temp->exp);
        else
            printf("%d*x^%d", temp->coef, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int n, i, coef, exp;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the coefficient %d: ", i + 1);
        scanf("%d", &coef);
        printf("Enter the exponent %d: ", i + 1);
        scanf("%d", &exp);
        insert1(coef, exp);
    }
    printf("The first polynomial is:\n");
    display(head1);
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the coefficient %d: ", i + 1);
        scanf("%d", &coef);
        printf("Enter the exponent %d: ", i + 1);
        scanf("%d", &exp);
        insert2(coef, exp);
    }
    printf("\nThe second polynomial is:\n");
    display(head2);
    add();
    printf("\nThe sum of the two polynomials is:\n");
    display(head3);
    return 0;
}
