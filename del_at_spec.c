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

// Function to insert a new node at the end of the linked list
struct Node* insertNodeAtEnd(struct Node* head, int data) {
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

    struct Node* current = head;
    struct Node* previous = NULL;

    // Traverse the list to find the node to be deleted
    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    // If the node to be deleted is the first node
    if (current == head) {
        head = head->next;
        free(current);
    } else if (current != NULL) {
        // If the node to be deleted is not the first node
        previous->next = current->next;
        free(current);
    } else {
        printf("Node with key %d not found.\n", key);
    }

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
    int data, key;
    time_t t;
 time(&t);
 printf("Current date and time is :%s", ctime(&t));
 printf("BT23CSH053 (Mohd Inzamamul Haque)\n");

    // Taking user input to create a linked list;
    printf("Enter the elements of the linked list (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        head = insertNodeAtEnd(head, data);
    }

    // Printing the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Taking user input for the node to be deleted
    printf("Enter the element to be deleted: ");
    scanf("%d", &key);

    // Deleting the specific node
    head = deleteNode(head, key);

    // Printing the updated linked list
    printf("Linked List after deleting node with key %d: ", key);
    printList(head);

    return 0;
}
