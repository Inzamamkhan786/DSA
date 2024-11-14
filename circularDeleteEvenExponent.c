#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
int exponent;
struct node* next;
};



struct node* insert(struct node*head, struct node*tail, int data, int expo);
struct node* createNode(int value, int expo);
void deleteNode(struct node*head, struct node*tail);
void printNode(struct node*head, struct node* tail);



int main(){
    struct node* head = NULL;
    struct node* tail = NULL;

    insert(head,tail,10,5);
    insert(head,tail,116,5);
    insert(head,tail,18,4);
    insert(head,tail,87,3);
    insert(head,tail,45,2);
    insert(head,tail,23,1);
    insert(head,tail,78,0);

    deleteNode(head,tail);
    printNode(head,tail);


    return 0;
}


struct node* createNode(int value, int expo){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->exponent = expo;
    newNode->next = NULL;
    return newNode;
}


struct node* insert(struct node*head, struct node*tail, int data, int expo){
    if(head == NULL){
        //first node;
        struct node* newNode = createNode(data,expo);
        head = newNode;
        tail = newNode;
     }else{
        struct node* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        tail = ptr;
        tail->next = head;
    }
    return head;

}


void deleteNode(struct node* head, struct node* tail){
    if(head == NULL){
        return;
    }
   struct node*current = head;
   struct node*prev = tail;


    do{
        if((head->exponent)%2==0){
        head = head->next;
        tail->next = head;    
        }

        if((tail->exponent)%2==0){
            struct node*str = head;
            while(str->next!=tail){
                str = str->next;
            }
            tail = str;
            tail->next = head;
        }

    current = current->next;
    prev = prev->next;
     
     if((current->exponent)%2==0){
        prev->next = current->next;
     }

    }while(current != tail->next);
return;
}


void printNode(struct node*head, struct node* tail){
    struct node*ptr = head;
    do{
        printf("%d ->", ptr->data);
        ptr = ptr->next;

    }while(ptr != tail->next);
}