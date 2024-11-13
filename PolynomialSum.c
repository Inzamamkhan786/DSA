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

// Function to insert a term into a polynomial linked list in sorted order
void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    struct Node* current = *head;
    struct Node* prev = NULL;

    // Insert in descending order of exponent
    while (current != NULL && current->exp >exp) {
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

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    // Traverse both linked lists
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0) {
                insertTerm(&result, sum, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // If any terms remain in poly1
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    // If any terms remain in poly2
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
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
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n1, n2, coeff, exp;

    // Input the first polynomial
    printf("Enter the number of terms in polynomial A: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    // Input the second polynomial
    printf("Enter the number of terms in polynomial B: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);

    // Display the resulting polynomial
    printf("Resultant polynomial after addition: ");
    displayPolynomial(result);

    // Free the allocated memory
    struct Node* temp;
    while (poly1 != NULL) {
        temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }
    while (poly2 != NULL) {
        temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }
    while (result != NULL) {
        temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
