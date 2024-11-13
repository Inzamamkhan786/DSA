#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
    int priority;
};
struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int m,int p);
void display(struct node*front);
struct node*createNode(int m,int p);
void display(struct node*front);

int main(){
    enqueue(7,2);
    enqueue(22,4);
    enqueue(78,1);
    enqueue(786,3);
    enqueue(99,6);
    enqueue(51,5);

    display(front);
   

    return 0;
}

void enqueue(int m, int p){
struct node*newNode = createNode(m,p);
if(newNode == NULL){
    printf("Overflow\n");
    return;
}
if(front==NULL || rear==NULL){
    front = rear = newNode;
    return;
}

if(newNode->priority < front->priority){
    newNode->next = front;
    front = newNode;
    return;
}

if(newNode->priority > rear->priority){
    rear->next = newNode;
    rear = newNode;
    return;
}


struct node*temp = front;
    while(temp->next!=NULL && temp->next->priority <= newNode->priority){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    if(temp == rear){
        rear = newNode;
    }

}



struct node*createNode(int m,int p){
    struct node*newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=m;
    newNode->priority = p;
    newNode->next = NULL;
    return newNode;
}


void display(struct node*front){
    struct node*str;
    str = front;
    while(str!=NULL){
        printf("%d ", str->data);
        str = str->next;
    }
    return;
}