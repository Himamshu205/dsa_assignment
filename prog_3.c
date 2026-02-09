#include <stdio.h>
#include <stdlib.h>

/* Definition of a node */
struct Node {
    int data;
    struct Node *next;
};

/* Insert node at the beginning */
void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

/* Display list in normal order */
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* Reverse traversal using recursion */
void reverseTraversal(struct Node *head) {
    if (head == NULL)
        return;

    reverseTraversal(head->next);
    printf("%d -> ", head->data);
}

int main() {
    struct Node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printf("Linked List (Forward): ");
    display(head);

    printf("Linked List (Reverse): ");
    reverseTraversal(head);
    printf("NULL\n");

    return 0;
}
