/*
 * Doubly Linked List implementation in C
 * Features:
 *  - insert at head, insert at tail, insert after a value
 *  - delete by value, search
 *  - display forward and backward
 *  - cleanup
 *
 * Simple interactive menu in main to test functionality.
 * Compile (on Windows with gcc):
 * gcc -o LinkedList LinkedList.c
 * ./LinkedList
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Create a new node with given value
Node* create_node(int value) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    n->data = value;
    n->prev = n->next = NULL;
    return n;
}

// Insert at head
void insert_head(Node **head, Node **tail, int value) {
    Node *n = create_node(value);
    if (*head == NULL) {
        *head = *tail = n;
        return;
    }
    n->next = *head;
    (*head)->prev = n;
    *head = n;
}

// Insert at tail
void insert_tail(Node **head, Node **tail, int value) {
    Node *n = create_node(value);
    if (*tail == NULL) {
        *head = *tail = n;
        return;
    }
    (*tail)->next = n;
    n->prev = *tail;
    *tail = n;
}

// Insert after the first node with target value. Returns true if inserted.
bool insert_after(Node **head, Node **tail, int target, int value) {
    Node *cur = *head;
    while (cur) {
        if (cur->data == target) {
            Node *n = create_node(value);
            n->next = cur->next;
            n->prev = cur;
            cur->next = n;
            if (n->next)
                n->next->prev = n;
            else
                *tail = n; // inserted at end
            return true;
        }
        cur = cur->next;
    }
    return false;
}

// Delete first node with value. Returns true if deleted.
bool delete_value(Node **head, Node **tail, int value) {
    Node *cur = *head;
    while (cur) {
        if (cur->data == value) {
            if (cur->prev)
                cur->prev->next = cur->next;
            else
                *head = cur->next; // removing head

            if (cur->next)
                cur->next->prev = cur->prev;
            else
                *tail = cur->prev; // removing tail

            free(cur);
            return true;
        }
        cur = cur->next;
    }
    return false;
}

// Search for value, returns pointer or NULL
Node* search(Node *head, int value) {
    Node *cur = head;
    while (cur) {
        if (cur->data == value) return cur;
        cur = cur->next;
    }
    return NULL;
}

// Display forward
void display_forward(Node *head) {
    Node *cur = head;
    printf("List (forward): ");
    if (!cur) {
        printf("(empty)\n");
        return;
    }
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf(" <-> ");
        cur = cur->next;
    }
    printf("\n");
}

// Display backward
void display_backward(Node *tail) {
    Node *cur = tail;
    printf("List (backward): ");
    if (!cur) {
        printf("(empty)\n");
        return;
    }
    while (cur) {
        printf("%d", cur->data);
        if (cur->prev) printf(" <-> ");
        cur = cur->prev;
    }
    printf("\n");
}

// Free entire list
void cleanup(Node **head, Node **tail) {
    Node *cur = *head;
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    *head = *tail = NULL;
}

// Simple interactive menu
int main(void) {
    Node *head = NULL, *tail = NULL;
    int choice = 0;
    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Insert after value\n");
        printf("4. Delete value\n");
        printf("5. Search value\n");
        printf("6. Display forward\n");
        printf("7. Display backward\n");
        printf("8. Cleanup and exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            // clear input
            int c; while ((c = getchar()) != '\n' && c != EOF) ;
            printf("Invalid input. Try again.\n");
            continue;
        }

        int val, target;
        bool res;
        Node *found;

        switch (choice) {
            case 1:
                printf("Value to insert at head: ");
                if (scanf("%d", &val) == 1) insert_head(&head, &tail, val);
                break;
            case 2:
                printf("Value to insert at tail: ");
                if (scanf("%d", &val) == 1) insert_tail(&head, &tail, val);
                break;
            case 3:
                printf("Target value to insert after: ");
                if (scanf("%d", &target) != 1) break;
                printf("Value to insert: ");
                if (scanf("%d", &val) != 1) break;
                res = insert_after(&head, &tail, target, val);
                printf(res ? "Inserted after %d\n" : "Target %d not found\n", target);
                break;
            case 4:
                printf("Value to delete: ");
                if (scanf("%d", &val) != 1) break;
                res = delete_value(&head, &tail, val);
                printf(res ? "Deleted %d\n" : "Value %d not found\n", val);
                break;
            case 5:
                printf("Value to search: ");
                if (scanf("%d", &val) != 1) break;
                found = search(head, val);
                if (found)
                    printf("Found %d (node at %p)\n", val, (void*)found);
                else
                    printf("%d not found\n", val);
                break;
            case 6:
                display_forward(head);
                break;
            case 7:
                display_backward(tail);
                break;
            case 8:
                cleanup(&head, &tail);
                printf("Cleaned up and exiting.\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
// Linked List implementation in C
