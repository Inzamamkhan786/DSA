#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a term in the polynomial
struct Node {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
    struct Node* next;  // Pointer to the next term
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial linked list
void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    struct Node* current = *head;
    struct Node* prev = NULL;

    // Insert in descending order of exponent
    while (current != NULL && current->exp > exp) {
        prev = current;
        current = current->next;
    }

    // If term with same exponent exists, add the coefficients
    if (current != NULL && current->exp == exp) {
        current->coeff += coeff;
        if (current->coeff == 0) {  // If coefficient becomes 0, remove the term
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
        }
        free(newNode);  // No need to add new node, so free it
    } else {
        // Insert new node at the correct position
        if (prev == NULL) {
            newNode->next = *head;
            *head = newNode;
        } else {
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }
}

// Function to display the polynomial
void displayPolynomial(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->exp);
        current = current->next;
        if (current != NULL) {
            if (current->coeff > 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        }
    }
    printf("\n");
}

int main() {
    struct Node* poly = NULL;
    int n, coeff, exp;

    // Input the first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }

    // Input the second polynomial and add it directly
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }

    // Display the resulting polynomial
    printf("Resultant polynomial after addition: ");
    displayPolynomial(poly);

    // Free the allocated memory
    struct Node* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }

    return 0;
}
