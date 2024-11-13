#include <stdio.h>
#include <stdlib.h>

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
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to find the maximum element in the linked list
int findMax(struct Node* head) {
    int max = head->data;
    struct Node* current = head->next;
    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

// Function to perform Radix Sort
void radixSort(struct Node** head) {
    int max = findMax(*head);
    int exp = 1;
    struct Node* buckets[10] = {NULL};
    struct Node* lastNodes[10] = {NULL};
    struct Node* current = NULL;
    
    while (max / exp > 0) {
        // Distribute elements into buckets
        current = *head;
        while (current != NULL) {
            int index = (current->data / exp) % 10;
            if (buckets[index] == NULL) {
                buckets[index] = current;
            } else {
                lastNodes[index]->next = current;
            }
            lastNodes[index] = current;
            current = current->next;
        }

        // Reassemble the list from the buckets
        int j = 0;
        while (j < 10 && buckets[j] == NULL) {
            j++;
        }
        *head = buckets[j];
        current = lastNodes[j];

        while (++j < 10) {
            if (buckets[j] != NULL) {
                current->next = buckets[j];
                current = lastNodes[j];
            }
        }
        current->next = NULL;

        // Reset buckets and lastNodes
        for (int i = 0; i < 10; i++) {
            buckets[i] = NULL;
            lastNodes[i] = NULL;
        }
        
        exp *= 10;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements into the linked list
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    // Print the original list
    printf("Original list: ");
    printList(head);

    // Perform Radix Sort
    radixSort(&head);

    // Print the sorted list
    printf("Sorted list: ");
    printList(head);

    // Free the allocated memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
