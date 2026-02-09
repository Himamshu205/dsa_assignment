#include <stdio.h>
#include <stdlib.h>

/* Doubly linked list node */
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

/* Create a new node */
struct Node* createNode(int value) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = value;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

/* Insert at end (helper to build list easily) */
void insertEnd(struct Node **head, int value) {
    struct Node *n = createNode(value);

    if (*head == NULL) {
        *head = n;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

/* Display list forward */
void displayForward(struct Node *head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* Find first node with given value */
struct Node* findNode(struct Node *head, int value) {
    while (head != NULL) {
        if (head->data == value) return head;
        head = head->next;
    }
    return NULL;
}

/* Insert a new node AFTER a given node pointer */
void insertAfter(struct Node *node, int value) {
    if (node == NULL) return;

    struct Node *n = createNode(value);

    n->next = node->next;
    n->prev = node;

    if (node->next != NULL)
        node->next->prev = n;

    node->next = n;
}

/* Delete the first node that contains the given value */
void deleteValue(struct Node **head, int value) {
    if (*head == NULL) return;

    struct Node *temp = *head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) return; /* not found */

    if (temp == *head)            /* deleting head */
        *head = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

int main() {
    struct Node *head = NULL;

    /* Build list: 10 <-> 20 <-> 30 */
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    printf("Initial List: ");
    displayForward(head);

    /* Insert 25 after node with value 20 */
    struct Node *node20 = findNode(head, 20);
    insertAfter(node20, 25);

    printf("After insertAfter(20, 25): ");
    displayForward(head);

    /* Delete node with value 10 */
    deleteValue(&head, 10);

    printf("After deleteValue(10): ");
    displayForward(head);

    return 0;
}
