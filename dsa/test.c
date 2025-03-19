#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void createLoop(struct Node* head, int position) {
    struct Node* temp = head;
    struct Node* loopNode = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == position)
            loopNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = loopNode;
}

int countLoopLength(struct Node* head) {
    struct Node *slow = head, *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int loopLength = 1;
            struct Node* temp = slow;
            while (temp->next != slow) {
                loopLength++;
                temp = temp->next;
            }
            return loopLength;
        }
    }
    return 0;
}

int main() {
    struct Node* head = NULL;
    int n, value, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }

    printf("Enter loop position (1-based index, 0 for no loop): ");
    scanf("%d", &position);
    if (position > 0)
        createLoop(head, position);

    int loopLength = countLoopLength(head);
    if (loopLength > 0)
        printf("Loop detected! Length of loop: %d\n", loopLength);
    else
        printf("No loop detected.\n");

    return 0;
}