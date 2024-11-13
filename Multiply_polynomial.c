#include<stdio.h>
#include<stdlib.h>

//polynomial 1 == 4x^3 + 3x^2 + 7x + 2;
//polynomial 2 == 7x^6 + 8x^2 - 5x + 9;



struct node{
int coeff;
int expo;
struct node* next;
};

void polynomial(struct node** head,int coeffecient,int exponent);
struct node*Multiply(struct node* head1,struct node* head2);
void display(struct node* head3);
struct node*createNode(int coeffecient,int exponent);



int main(){
    struct node *head1,*head2,*head3;
    head1 = NULL;
    head2 = NULL;
    head3 = NULL;
    //Creating the polynomial1;

    polynomial(&head1,4,3);
    polynomial(&head1,3,2);
    polynomial(&head1,7,1);
    polynomial(&head1,2,0);


    //creating the polynomial2;
    
    polynomial(&head2,8,2);
    polynomial(&head2,-5,1);
    polynomial(&head2,9,0);

    head3 = Multiply(head1,head2);

    display(head3);


    return 0;
}


void polynomial(struct node**head,int coeffecient,int exponent){
struct node*newNode = createNode(coeffecient,exponent);
    if((*head) == NULL){
        //first node;
        (*head) = newNode;      
    }else{
        struct node*ptr = (*head);
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}



struct node*createNode(int coeffecient,int exponent){
    struct node*newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeffecient;
    newNode->expo = exponent;
    newNode->next = NULL;
    return newNode;
}

struct node*Multiply(struct node*head1,struct node*head2){
    struct node*ptr1,*ptr2,*head3;
    ptr1 = head1;
    ptr2 = head2;
    head3 = NULL;
    
    while(ptr1 != NULL){
       while(ptr2!=NULL){
        polynomial(&head3,(ptr1->coeff)*(ptr2->coeff),(ptr1->expo)+(ptr2->expo));
        ptr2 = ptr2->next;
       }
       ptr2 = head2;
       ptr1 = ptr1->next;
}
return head3;
}


void display(struct node*head){
    struct node*temp = head;
    while(temp!=NULL){
        printf("%dx^%d ", temp->coeff,temp->expo);
         if(temp->next!=NULL){
            printf("+ ");
         }
        temp = temp->next;
    }
}