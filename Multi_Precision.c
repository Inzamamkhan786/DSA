#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};
struct node* insert(struct node*head1,int d);
struct node*createNode(int d);
struct node* add(struct node*head1,struct node* head2);
void display(struct node* head3);
void reverseList(struct node** head_ref);

int main(){
 char num1[50];
 char num2[50];

 struct node* head1,*head2,*head3;
 head1 = NULL;
 head2 = NULL;
 head3 = NULL;

 printf("Enter the first number: ");
 scanf("%s", num1);
 printf("Enter the second number : ");
 scanf("%s", num2);
 for(int i=0; num1[i]!='\0'; i++){
    head1 = insert(head1,(num1[i]-'0'));
 }

 for(int i=0; num2[i]!='\0'; i++){
    head2 = insert(head2,(num2[i]-'0'));
 }

 head3 = add(head1,head2);

 //Now reversing the head3 linked list;
 reverseList(&head3);

 display(head3);


    return 0;
}


struct node *insert(struct node*head,int d){
    struct node* newNode = createNode(d);
    struct node*ptr;
    ptr = head;
    if(head==NULL){
        head = newNode;
        return head;
    }else{
    while(ptr ->next!=NULL){
        ptr = ptr->next;
    }
        ptr->next = newNode;
        ptr = newNode; 
        return head;  
    }
}



struct node*createNode(int d){
    struct node*newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = d;
    newNode->next=NULL;
    return newNode;
}


struct node*add(struct node*head1, struct node*head2){
    int carry =0;
    struct node*num1,*num2,*head3;
    num1 = head1;
    num2 = head2;
    head3 = NULL;


    while(num1!=NULL || num2!=NULL || carry){
        int sum = carry;
        if(num1!=NULL){
            sum = sum+num1->data;
            num1 = num1->next;
        }

        if(num2!=NULL){
            sum = sum+num2->data;
            num2 = num2->next;
        }
        head3 = insert(head3,sum%10);
        carry = sum/10;
    }
    return head3;
}



void display(struct node* head3){
    struct node*temp;
    temp=head3;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}

void reverseList(struct node** head_ref){
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }

    *head_ref = prev; // Update the head to the new first node
}
