#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node*enqueue(struct node**front,struct node**rear,int m);
struct node*createNode(int m);
void display(struct node* front);

int main(){
    struct node*Front=NULL;
    struct node* Rear=NULL;
    enqueue(&Front,&Rear,7);
    enqueue(&Front,&Rear,67);
    enqueue(&Front,&Rear,1);
    enqueue(&Front,&Rear,54);
    enqueue(&Front,&Rear,89);
    enqueue(&Front,&Rear,23);

display(Front);

    return 0;
}

struct node*enqueue(struct node**front,struct node**rear,int m){
    struct node*newNode = createNode(m);

    if(*front==NULL && *rear==NULL){
        *front=*rear=newNode;
    }else{
        if(newNode->data < (*front)->data){
            newNode->next=*front;
            *front=newNode;
        }else{
        struct node*temp=*front;
        while(temp->next!=NULL && temp->next->data < newNode->data){
            temp=temp->next;
        }
         newNode->next = temp->next;
            temp->next = newNode;

            if(newNode->next==NULL){
                *rear=newNode;
            }


        }
   
    }
    return *front;
}






struct node*createNode(int data){
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}


void display(struct node*front){
    struct node*temp;
    temp=front;
    while(temp->next!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}