#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node* createNode(int value);
void print(struct node**head);
struct node*circular(struct node**head);

int main(){
    struct node*head,*current1,*current2,*current3,*current4,*current5,*str;
    int i;
    current1=createNode(22);
    current2=createNode(15);
    current3=createNode(71);
    current4=createNode(62);
    current5=createNode(99);

    head=current1;
    current1->link=current2;
    current2->link=current3;
    current3->link=current4;
    current4->link=current5;
    current5->link=NULL;
     printf("\n");
     //printing the created linked list;
      print(&head);
      // attaching the first node with the last  node and making the linked list is  circular;
      circular(&head);
      //printing the linked list after circular node;
      print(&head);

    return 0;
}
struct node* createNode(int value){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->link=NULL;
    return newNode;
}
void print(struct node**head){
    struct node*ptr;
    ptr=*head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}

struct node*circular(struct node**head){
struct node* str;
str=*head;
while(str->link!=NULL){
    str=str->link;
}
str->link=*head;
return str;

}