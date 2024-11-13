//Queue implementationn with the linked list;

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
}*front=NULL,*rear=NULL;

struct node*Enqueue(int value);
void Dequeue();
void display();



int main(){
    Enqueue(5);
    Enqueue(4);
    Enqueue(3);
    Enqueue(2);
    Enqueue(1);
    display();
    
    Dequeue();
    printf("\n");
    display();
    Dequeue();
    printf("\n");
    display();

    return 0;
}

struct node*Enqueue(int value){
struct node*newNode;
newNode=(struct node*)malloc(sizeof(struct node));
newNode->data=value;
newNode->next=NULL;
if(front==NULL&&rear==NULL){
front=newNode;
rear=newNode;
}else{
    rear->next=newNode;
  rear=newNode;
}
return newNode;

}


void display(){
struct node*temp;
temp=front;
while(temp!=NULL){
    printf("%d ", temp->data);
    temp=temp->next;

}
}


void Dequeue(){
struct node*temp;
if(front==NULL){
    printf("The queue is empty\n");
    return;
}
temp=front;
front=front->next;
free(temp);
}