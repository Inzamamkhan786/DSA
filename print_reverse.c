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

// Function to print a linked list in reverse order
void printReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }

    // Recursively call the function for the next node
    printReverse(head->next);

    // Print the data of the current node
    printf("%d ", head->data);
}

// Driver program to test the printReverse function
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

    printf("Linked list in reverse order: ");
    printReverse(head);

    return 0;
}
