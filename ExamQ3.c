#include<stdio.h>
#include<stdlib.h>





struct node{
    int data;
    int priority;
    struct node*next;
};

struct node*front = NULL;
struct node*rear = NULL;
void enqueue(int m, int p);
struct node*createNode(int m, int p);
void display(struct node*front);


int main(){

    enqueue(7,2);
    enqueue(22,4);
    enqueue(78,6);
    enqueue(786,3);
    enqueue(99,1);
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
        //first element;
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

    struct node*ptr = front;
    while(ptr->next!=NULL && ptr->next->priority <= newNode->priority){
        ptr = ptr->next;
    }
    if(ptr == rear){
        rear->next = newNode;
        rear = newNode;
    }else{
        newNode->next = ptr->next;
        ptr->next = newNode;
    }

return;


}



struct node*createNode(int m, int p){
    struct node*newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = m;
    newNode->priority = p;
    newNode->next = NULL;

 return newNode;
}


void display(struct node*front){
    struct node*temp = front;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}