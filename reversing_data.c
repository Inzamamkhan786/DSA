#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list in reverse order
void printReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    // Recursively call the function for the next node
    printReverse(head->next);
    // Print the data of the current node
    printf("%d ", head->data);
}

int main() {
    struct Node* head = NULL;
    time_t t;
time(&t);
printf("Current date and time is :%s", ctime(&t));
printf("BT23CSH053 (Mohd Inzamamul Haque)\n");

    // Inserting elements at the beginning of the linked list
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Print the linked list in reverse order
    printf("Linked List in Reverse Order: ");
    printReverse(head);

    return 0;
}
