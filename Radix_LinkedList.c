#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node*next;
};


void insert(struct node**head , int m);
struct node*createNode(int m);

void display(struct node*head);


int main(){

struct node*head = NULL;
printf("Enter the number of inputs you want : ");
int n;
scanf("%d", &n);

for(int i=1; i<=n; i++){
    int m;
    printf("Enter data number %d : ", i);
    scanf("%d", &m);
    insert(&head,m);
}

display(head);


return 0;

}



void insert(struct node**head , int m){
    struct node* newNode=createNode(m);
    struct node*temp=*head;
    if(temp==NULL){
        temp=newNode;
        return;
    }else{
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp=newNode;
    return;
    }


}


struct node*createNode(int m){
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=m;
    newNode->next=NULL;
    return newNode;

}


void display(struct node*head){
    struct node*ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }

}