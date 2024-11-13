#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to delete the first node in the linked list
struct Node* deleteFirstNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4
    time_t t;
 time(&t);
 printf("Current date and time is :%s", ctime(&t));
 printf("BT23CSH053 (Mohd Inzamamul Haque)\n");
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Printing the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Deleting the first node
    head = deleteFirstNode(head);

    // Printing the updated linked list
    printf("Linked List after deleting the first node: ");
    printList(head);

    return 0;
}
