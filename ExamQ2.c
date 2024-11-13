#include<stdio.h>
#include<stdlib.h>

/* A = 4x^2 + 7x + 12;
   B = 6x^3 + 5x + 16;
   result = A+B = 6x^3 + 4x^2 + 12x + 28;
*/

struct node{
    int coeff;
    int expo;
    struct node* next;
};

void polynomial(struct node**head,int coeffecient, int exponent);
struct node* createNode(int c,int e);
struct node*add(struct node*head1,struct node*head2);
void display(struct node*head);


int main(){
    struct node *head1,*head2,*head3;
    head1 = NULL;
    head2 = NULL;
    head3 = NULL;

    //Creating polynomial1;
polynomial(&head1,4,2);
polynomial(&head1,7,1);
polynomial(&head1,12,0);
    
    //Creating the polynomial2;
polynomial(&head2,6,3);
polynomial(&head2,5,1);
polynomial(&head2,16,0);


head3 = add(head1,head2);

display(head3);

    return 0;
}


void polynomial(struct node**head,int coeffecient,int exponent){
    struct node*newNode = createNode(coeffecient,exponent);

    if((*head) == NULL){
     (*head) = newNode;
     newNode->next = NULL;
    }else{
    struct node* ptr = (*head);

    while(ptr->next!=NULL){
      ptr = ptr->next;
    }
    ptr->next = newNode;

    }

}



struct node*createNode(int c,int e){
    struct node*newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = c;
    newNode->expo = e;
    newNode->next = NULL;
    return newNode;
}



struct node*add(struct node*head1,struct node*head2){
    struct node*ptr1,*ptr2,*head3;
    ptr1 = head1;
    ptr2 = head2;
    head3 = NULL;

    while(ptr2!=NULL && ptr1!=NULL){

       
    if(ptr2->expo > ptr1->expo){
     polynomial(&head3,ptr2->coeff,ptr2->expo);
        ptr2 = ptr2->next;
    }

    if(ptr1->expo > ptr2->expo){
        polynomial(&head3,ptr1->coeff,ptr1->expo);
        ptr1 = ptr1->next;
    }

    if(ptr2->expo == ptr1->expo){
        polynomial(&head3,(ptr1->coeff)+(ptr2->coeff),(ptr1->expo));
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
        }

        while(ptr1!=NULL){
            polynomial(&head3,ptr1->coeff,ptr1->expo);
            ptr1= ptr1->next;
        }

      while(ptr2!=NULL){
            polynomial(&head3,ptr2->coeff,ptr2->expo);
            ptr2= ptr2->next;
        }

    
    return head3;
}



void display(struct node*head){
struct node*temp = head;

while(temp!=NULL){
    printf("%dx^%d", temp->coeff,temp->expo);
    if(temp->next!=NULL){
        printf(" + ");
    }
    temp = temp->next;
}

}