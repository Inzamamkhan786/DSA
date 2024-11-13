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

// Function to insert a node at the end of the linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to delete a specific node in the linked list
struct Node* deleteNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return NULL;
    }

    // If the key is in the first node
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    // Traverse to find the node with the given key
    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    // If the key is not found
    if (current == NULL) {
        printf("Node with key %d not found.\n", key);
        return head;
    }

    // Delete the node
    previous->next = current->next;
    free(current);

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
    struct Node* head = NULL;
     time_t t;
 time(&t);
 printf("Current date and time is :%s", ctime(&t));
 printf("BT23CSH053 (Mohd Inzamamul Haque)\n");

    // Inserting elements into the linked list
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);

    // Printing the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Deleting a specific node provided by the user
    int key;
    printf("Enter the node value to delete: ");
    scanf("%d", &key);

    head = deleteNode(head, key);

    // Printing the updated linked list
    printf("Linked List after deleting node with value %d: ", key);
    printList(head);

    return 0;
}
