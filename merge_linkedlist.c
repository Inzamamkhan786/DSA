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

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node* current = NULL;

    // Check if either list is empty
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }

    // Initialize mergedList to the smaller of the first nodes of list1 and list2
    if (list1->data < list2->data) {
        mergedList = list1;
        list1 = list1->next;
    } else {
        mergedList = list2;
        list2 = list2->next;
    }

    // Set the current pointer to the mergedList
    current = mergedList;

    // Merge the lists
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // If there are remaining nodes in list1 or list2, append them to the mergedList
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return mergedList;
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
    // Creating two sorted linked lists: 1->3->5 and 2->4->6
    time_t t;
time(&t);
printf("Current date and time is :%s", ctime(&t));
printf("BT23CSH053 (Mohd Inzamamul Haque)\n");
    struct Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    struct Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    // Printing the original linked lists
    printf("Original Linked List 1: ");
    printList(list1);
    printf("Original Linked List 2: ");
    printList(list2);

    // Merging the two sorted linked lists
    struct Node* mergedList = mergeSortedLists(list1, list2);

    // Printing the merged linked list
    printf("Merged Linked List: ");
    printList(mergedList);

    return 0;
}
