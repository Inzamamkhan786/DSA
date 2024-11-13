#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to reverse a linked list
void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Save the next node
        current->next = prev;   // Reverse the link
        prev = current;         // Move to the next nodes
        current = next;
    }

    *head_ref = prev; // Set the new head
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Driver program to test the reverseList function
int main() {
    struct Node* head = NULL;
    time_t t;
time(&t);
printf("Current date and time is :%s", ctime(&t));
printf("BT23CSH053 (Mohd Inzamamul Haque)\n");

    // Insert elements into the linked list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Original linked list: ");
    printList(head);

    // Reverse the linked list
    reverseList(&head);

    printf("Reversed linked list: ");
    printList(head);

    return 0;
}
