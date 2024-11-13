#include <stdio.h>
#include <stdlib.h>

#define RADIX 10 // Base 10 for decimal numbers

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
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to get the maximum value in the linked list
int getMax(struct Node* head) {
    int max = head->data;
    while (head != NULL) {
        if (head->data > max) {
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

// Function to perform counting sort on the linked list based on a digit
void countingSort(struct Node** head, int exp) {
    struct Node* output = NULL; // Output linked list
    struct Node* buckets[RADIX] = {NULL}; // Array of linked lists for each bucket
    struct Node* temp = *head;

    // Place nodes into buckets based on the current digit
    while (temp != NULL) {
        int index = (temp->data / exp) % RADIX;
        insertEnd(&buckets[index], temp->data);
        temp = temp->next;
    }

    // Reconstruct the linked list by concatenating the buckets
    for (int i = 0; i < RADIX; i++) {
        if (buckets[i] != NULL) {
            if (output == NULL) {
                output = buckets[i];
            } else {
                struct Node* temp = output;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = buckets[i];
            }
        }
    }

    *head = output;
}

// Function to perform radix sort on the linked list
void radixSort(struct Node** head) {
    int max = getMax(*head);
    for (int exp = 1; max / exp > 0; exp *= RADIX) {
        countingSort(head, exp);
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to test radix sort on a linked list
int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insertEnd(&head, 170);
    insertEnd(&head, 45);
    insertEnd(&head, 75);
    insertEnd(&head, 90);
    insertEnd(&head, 802);
    insertEnd(&head, 24);
    insertEnd(&head, 2);
    insertEnd(&head, 66);

    printf("Original list:\n");
    printList(head);

    radixSort(&head);

    printf("Sorted list:\n");
    printList(head);

    return 0;
}